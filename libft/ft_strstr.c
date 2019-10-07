/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:08:31 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:08:33 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	int		b;
	int		l;
	int		size;

	b = 0;
	l = 0;
	size = 0;
	while (little[size])
		size++;
	if (size == 0)
		return (big);
	while (big[b])
	{
		while (little[l] == big[b + l])
		{
			if (l == size - 1)
				return (big + b);
			l++;
		}
		l = 0;
		b++;
	}
	return (NULL);
}
