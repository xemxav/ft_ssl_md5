/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:08:04 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:08:05 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	size;

	size = 0;
	while (little[size])
		size++;
	if (size == 0)
		return (big);
	while (*big && len-- >= size)
		if (ft_memcmp(big++, little, size) == 0)
			return ((char *)(big - 1));
	return (NULL);
}
