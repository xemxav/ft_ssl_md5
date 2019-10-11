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

static void				bourrage(t_control *control, ssize_t ret, int i)
{

}

static int 			hash_buff(t_control *control, ssize_t ret, int i)
{

	// si ret < 4 il va falloir reappeller hash buff dans hash buff
	control->size += ret;
	if (i < 15 || ret < 4)
		bourrage(control, ret, i);
	printf("je hash buf\n");
	return (0);
}

int					hash_a_file(t_control *control)
{
	int 			fd;
	ssize_t			ret;
	unsigned int 	buf[16];
	int				i;

	if ((fd = open(control->message, O_RDONLY)) < 0)
		return (md5_sha256_usage(control->hash, '\0', control->message));
	i = 0;
	ft_bzero((void*)&buf, sizeof(int) * 16);
	while ((ret = read(fd, &control->buf[i], 4)) != -1)
	{
		printf("i = %d\n", i);
		if (i == 15 || ret < 4)
		{
			hash_buff(control, ret, i);
			ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
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
	print_control(control);
	if (control->type == FILE)
		hash_a_file(control);
	reset_control(control);
	return (1);
}