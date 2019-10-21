/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:30:03 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 17:30:03 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"



static void				print_buf(t_control *control)
{
	int i = 0;
	while (i < 16)
	{
		printf("%#x ", control->buf[i]);
		i++;
	}
	printf("\n");
}

void				hash_buf(t_control *control)
{
	print_buf(control);
	ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
}

static void				padding(t_control *control, ssize_t ret, int i)
{
	printf("ret dans paddinf = %zd et i = %d\n", ret, i);
	if (ret < 4)
	{
		control->buf[i] = control->buf[i] | (0x80000000 >> (ret * 8));
		printf("buf = %#x\n", control->buf[i]);
		control->byte_count += (4 - ret) * 8;
		i++;
	}
	else
	{
		i++;
		control->buf[i] = 0x80000000;
		control->byte_count += 32;
		printf("buf n = %#x\n", control->buf[i]);
	}
	while (control->byte_count % 512 != 448)
	{
		if (i == 15)
		{
			i = 0;
			hash_buf(control);
		}
		control->byte_count += 32;
		i++;
	}
	control->buf[14] = (unsigned int)(control->size >> 32);
	control->buf[15] = (unsigned int)(control->size & 0xFFFFFFFF);
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
	hash_buf(control);
	printf("size = %zd\n", control->size);
	printf("byte count = %zd\n", control->byte_count);
	return (1);
}

int					hash_a_file(t_control *control)
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
        printf(" i = %d et ret = %zd\n", i, ret);
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

int				md5(t_control *control)
{
	if (control->type == FILE)
		control->file_only = 1;
	control->has_worked = 1;
//	print_control(control);
	if (control->type == FILE)
		hash_a_file(control);
	reset_control(control);
	return (1);
}