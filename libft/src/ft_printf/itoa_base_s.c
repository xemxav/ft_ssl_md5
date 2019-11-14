/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   itoa_base_s.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 11:42:19 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	basecount(long long n, int base)
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

static char		*make_nbr(long long n, int base, int isneg, size_t lenstr)
{
	char		*ref;
	char		*str;

	ref = ft_strdup("0123456789abcdef");
	if (n < 0)
	{
		isneg = 1;
		n = -n;
		lenstr = 1;
	}
	lenstr += basecount(n, base);
	str = ft_strnew(lenstr);
	lenstr -= 1;
	while ((int)lenstr >= 0)
	{
		str[(int)lenstr] = ref[n % base];
		n /= base;
		lenstr--;
	}
	if (isneg == 1)
		str[0] = '-';
	ft_strdel(&ref);
	return (str);
}

char			*itoa_base_s(long long n, int base)
{
	size_t		lenstr;
	int			isneg;

	isneg = 0;
	lenstr = 0;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	return (make_nbr(n, base, isneg, lenstr));
}
