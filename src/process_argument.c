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

static void				padding(t_control *control, ssize_t ret, int i)
{
	if (ret && ret < 4)
		control->buf[i] = control->buf[i] | (0x80 << (ret * 8));
	else
		control->buf[i] = 0x80;
	if (i + 1 > 14)
		control->hash_func(control);
	if (control->hash_func == &hash_sha256_buf)
		ft_memrev(&control->size, sizeof(char), 8);
	control->buf[15] = (unsigned int)(control->size >> 32);
	control->buf[14] = (unsigned int)(control->size & 0xFFFFFFFF);
	control->end_message = 1;
}

static int				hash_a_string(t_control *control)
{
	size_t				len;

	if (control->end_message)
	{
		control->message -= control->size / 8;
		return (1);
	}
	len = ft_strlen(control->message);
	ft_memcpy(control->buf, control->message, len);
	control->size += len * 8;
	control->message += len;
	if (len < 64)
		padding(control, len % 4, (int)(len / 4));
	control->hash_func(control);
	return (hash_a_string(control));
}

static int				read_a_fd(t_control *control, int fd)
{
	int					i;

	if (control->end_message)
		return (1);
	i = 0;
	while (i < 64 && read(fd, (unsigned char*)control->buf + i, 1))
	{
		control->size += 8;
		if (control->type == STDIN && control->p)
			record_message(control, i);
		i++;
	}
	if (i < 64)
		padding(control, i % 4, i / 4);
	control->hash_func(control);
	return (read_a_fd(control, fd));
}

static int				get_fd(t_control *control)
{
	int					fd;

	if ((fd = open(control->message, O_RDONLY)) < 0)
		return (md5_sha256_usage(control->hash, '\0', control->message));
	else
		return (fd);
}

int						process_argument(t_control *control)
{
	int					fd;

	control->has_worked = 1;
	if (control->type == FILE)
	{
		control->file_only = 1;
		if ((fd = get_fd(control)) < 0)
			return (TRUE);
		read_a_fd(control, fd);
		close(fd);
	}
	else if (control->type == STDIN)
		read_a_fd(control, 0);
	else if (control->type == STRING)
		hash_a_string(control);
	else
		return (FALSE);
	print_result(control);
	reset_control(control);
	return (TRUE);
}
