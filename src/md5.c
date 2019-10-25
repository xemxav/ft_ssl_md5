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

void				hash_buf(t_control *control)
{
    unsigned  int             A;
    unsigned  int             B;
    unsigned  int             C;
    unsigned  int             D;
    unsigned int             i;
    unsigned int    F;
    unsigned int    g;

    i = 0;
    g = 0;
    F = 0;
	if (control->md5_worker == NULL)
	{
		if (!init_md5_worker(control))
			return ;
	}
	A = control->md5_worker->A;
    B = control->md5_worker->B;
    C = control->md5_worker->C;
    D = control->md5_worker->D;
    while (i < 64)
    {
        if (i < 16)
        {
            F = (B & C) | ((~B) & D);
            g = i;
        }
        if (i >= 16 && i < 32)
        {
            F = (D & B) | ((~D) & C);
            g = (5 * i + 1) % 16;
        }
        if (i >= 32 && i < 48)
        {
            F = B ^ C ^ D;
            g = (3 * i + 5) % 16;
        }
        if (i >= 48 && i < 64)
        {
            F = C ^ (B | (~D));
            g = (7 * i) % 16;
        }
        F = F + A + control->md5_worker->K[i] + control->buf[g];
        A = D;
        D = C;
        C = B;
        B = B + lefttrotate(F, control->md5_worker->s[i]);
        i++;
    }
    control->md5_worker->A += A;
    control->md5_worker->B += B;
    control->md5_worker->C += C;
    control->md5_worker->D += D;
	ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
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
			hash_buf(control);
		}
		control->byte_count += 32;
		i++;
	}
	control->buf[15] = (unsigned int)(control->size >> 32);
	control->buf[14] = (unsigned int)(control->size & 0xFFFFFFFF);
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

void                print_digest(t_control *control)
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

int				md5(t_control *control)
{
	if (control->type == FILE)
		control->file_only = 1;
	control->has_worked = 1;
//	print_control(control);
	if (control->type == FILE)
		hash_a_file(control);
	print_digest(control);
	reset_control(control);
	return (1);
}
