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

void                print_digest(t_control *control)
{
	unsigned char   *tmp;
	unsigned int	*tmp2;
	int             k;

	k = 0;
//	print_control(control);
	if (control->type != STDIN && control->q == 0)
		ft_printf("%s (%s) = ", control->hash, control->message);
	if (control->type == STDIN && control->p == 1)
		ft_printf("%s", control->message);
	if (control->hash_func == &hash_md5_buf)
	{
		tmp = (unsigned char*)control->md5_worker;
		while (k < 16)
		{
			ft_printf("%.2x", tmp[k]);
			k++;
		}
	}
	else
	{
		tmp2 = (unsigned int*)control->sha_worker;
		while (k < 8)
		{
			ft_printf("%.8x", tmp2[k]);
			k++;
		}
	}
	ft_putchar('\n');
}