/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   itoa_base_u.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 13:43:28 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	basecount(unsigned long long int n, int base)
{
	size_t		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char			*itoa_base_u(unsigned long long int n, int base)
{
	size_t		lenstr;
	char		*str;
	char		*ref;

	lenstr = 0;
	ref = ft_strdup("0123456789abcdef");
	lenstr = lenstr + basecount(n, base);
	str = ft_strnew(lenstr);
	lenstr -= 1;
	while ((int)lenstr >= 0)
	{
		str[(int)lenstr] = ref[n % base];
		n /= base;
		lenstr--;
	}
	ft_strdel(&ref);
	return (str);
}
