/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trees.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 13:40:59 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*run_signed(t_infos *infos, va_list ap)
{
	if (infos->j)
		return (itoa_base_s((intmax_t)va_arg(ap, intmax_t), 10));
	if (infos->z)
		return (itoa_base_s((size_t)va_arg(ap, long), 10));
	if (infos->ll || infos->convletter == 'D')
		return (itoa_base_s((long long)va_arg(ap, long long), 10));
	if (infos->l)
		return (itoa_base_s((long)va_arg(ap, long), 10));
	if (infos->hh)
		return (itoa_base_s((char)va_arg(ap, long), 10));
	if (infos->h)
		return (itoa_base_s((short)va_arg(ap, long), 10));
	return (itoa_base_s(va_arg(ap, int), 10));
}

static int	which_base(char c)
{
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'u' || c == 'U')
		return (10);
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'b' || c == 'B')
		return (2);
	return (0);
}

char		*run_unsigned(t_infos *infos, va_list ap)
{
	int		base;

	base = which_base(infos->convletter);
	if (infos->j)
		return (itoa_base_u((uintmax_t)va_arg(ap, uintmax_t), base));
	if (infos->z)
		return (itoa_base_u((ssize_t)va_arg(ap, ssize_t), base));
	if (infos->ll)
		return (itoa_base_u((unsigned long long)va_arg(ap, unsigned long long),
		base));
		if (infos->l || infos->convletter == 'U' || infos->convletter == 'B'
		|| infos->convletter == 'O')
		return (itoa_base_u((unsigned long)va_arg(ap, unsigned long), base));
	if (infos->hh)
		return (itoa_base_u((unsigned char)va_arg(ap, unsigned long), base));
	if (infos->h)
		return (itoa_base_u((unsigned short)va_arg(ap, unsigned long), base));
	return (itoa_base_u(va_arg(ap, unsigned int), base));
}
