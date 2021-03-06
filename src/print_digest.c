/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_digest.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xem <xem@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 11:48:35 by xem          #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 11:48:35 by xem         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void		print_digest(t_control *control)
{
	int				k;

	k = 0;
	while (k < control->reg_nb)
	{
		if (control->hash_func == &hash_md5_buf)
			ft_memrev(&(control->worker->reg[k]), sizeof(char), 4);
		ft_printf("%.8x", control->worker->reg[k]);
		k++;
	}
}

int				print_p_flag(t_control *control)
{
	ssize_t		i;
	ssize_t		size;

	i = 0;
	if (control->hash_func == &hash_sha256_buf)
		if (!ft_memrev(&control->size, sizeof(char), 8))
			return (ERROR);
	size = control->size / 8;
	while (i < size)
	{
		write(1, (void*)control->message + i, 1);
		i++;
	}
	return (TRUE);
}

int				print_result(t_control *control)
{
	if (!control->r && !control->q)
	{
		if (control->type == FILE)
			ft_printf("%s (%s) = ", control->hash_maj, control->message);
		if (control->type == STRING)
			ft_printf("%s (\"%s\") = ", control->hash_maj, control->message);
	}
	if (control->type == STDIN && control->p == 1)
		if (print_p_flag(control) == ERROR)
			return (ERROR);
	print_digest(control);
	if (control->r && !control->q)
	{
		if (control->type == FILE)
			ft_printf(" %s", control->message);
		if (control->type == STRING)
			ft_printf(" \"%s\"", control->message);
	}
	ft_putchar('\n');
	return (TRUE);
}
