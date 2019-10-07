/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:08:18 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:08:18 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	tmp;
	size_t	min;
	size_t	max;

	min = 0;
	max = ft_strlen(str) - 1;
	while (min <= max)
	{
		tmp = str[min];
		str[min] = str[max];
		str[max] = tmp;
		max--;
		min++;
	}
	return (str);
}
