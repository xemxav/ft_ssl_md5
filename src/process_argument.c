/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_argument.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 11:44:31 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 11:44:31 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void				write_size(t_control *control)
{
	if (control->hash_func == &hash_md5_buf)
	{
		control->buf[15] = (unsigned int)(control->size >> 32);
		control->buf[14] = (unsigned int)(control->size & 0xFFFFFFFF);
	}
	else if (control->hash_func == &hash_sha256_buf)
	{
		control->buf[14] = (unsigned int)(control->size >> 32);
		control->buf[15] = (unsigned int)(control->size & 0xFFFFFFFF);
	}
}

static void				padding(t_control *control, ssize_t ret, int i)
{
	if (ret && ret < 4)
	{
		control->buf[i] = control->buf[i] | (0x80 << (ret * 8));
		control->byte_count += (4 - ret) * 8;
	}
	else
	{
		control->buf[i] = 0x80;
		control->byte_count += 32;
	}
	i++;
	while (control->byte_count % 512 != 448 && control->byte_count < 448)
	{
		if (i == 15)
		{
			i = 0;
			control->hash_func(control);
		}
		control->byte_count += 32;
		i++;
	}
	write_size(control);
	control->end_message = 1;
}

int 			check_buf(t_control *control, ssize_t ret, int i)
{
	if (control->end_message)
		return (0);
	if (i < 15 || ret < 4)
	{
		control->byte_count = control->size;
		padding(control, ret, i);
	}
	return (control->hash_func(control));
}

static int					hash_a_file(t_control *control)
{
	int 			fd;
	ssize_t			ret;
	int				i;

	if ((fd = open(control->message, O_RDONLY)) < 0)
		return (md5_sha256_usage(control->hash, '\0', control->message));
	i = 0;
	while ((ret = read(fd, &control->buf[i], 4)) != -1)
	{
		control->size += ret * 8;
		if (i == 15 || ret < 4)
		{
			check_buf(control, ret, i);
			i = 0;
			if (ret == 0)
			{
				close(fd);
				return (0);
			}
		}
		else
			i++;
	}
	return (1);
}

static void                print_digest(t_control *control)
{
	unsigned char   *tmp;
	int             k;

	k = 0;
	tmp = (unsigned char*)control->md5_worker;
	while (k < 16)
	{
		ft_printf("%.2x", tmp[k]);
		k++;
	}
}

int				process_argument(t_control *control)
{
	control->has_worked = 1;
	if (control->type == FILE)
	{
		control->file_only = 1;
		hash_a_file(control);
	}
//	else if (control->type == STDIN)
//		hash_stdin(control);
//	else if (control->type == STRING)
//		hash_a_string(control);
	else
		return (FALSE);
	print_digest(control);
	reset_control(control);
	return (TRUE);
}
