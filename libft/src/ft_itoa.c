/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:01:50 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:02:01 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_fill(char *str, long n2, size_t len, int isneg)
{
	str[len] = '\0';
	len--;
	if (n2 == 0)
	{
		str[len] = '0';
		len--;
	}
	while (n2 > 0)
	{
		str[len] = (n2 % 10) + '0';
		n2 = n2 / 10;
		len--;
	}
	if (isneg == 1)
		str[len] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		isneg;
	size_t	stringlen;
	int		i;
	long	n2;

	i = 0;
	isneg = 0;
	stringlen = ft_intcount(n) + 1;
	n2 = n;
	if (n < 0)
	{
		isneg = 1;
		n2 = -n2;
		stringlen++;
	}
	if ((s = (char *)malloc(stringlen)) == NULL)
		return (NULL);
	return (ft_fill(s, n2, stringlen - 1, isneg));
}
