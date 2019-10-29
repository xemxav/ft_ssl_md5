/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 09:48:46 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 09:48:46 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int				hash_md5_buf(t_control *control)
{
	unsigned  int			 A;
	unsigned  int			 B;
	unsigned  int			 C;
	unsigned  int			 D;
	unsigned int			 i;
	unsigned int	F;
	unsigned int	g;

	i = 0;
	g = 0;
	F = 0;
	if (control->md5_worker == NULL)
	{
		if (!init_md5_worker(control))
			return (FALSE);
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
	return (TRUE);
}