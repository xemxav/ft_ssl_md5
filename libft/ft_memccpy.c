/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:03:13 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:03:15 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dtmp;
	unsigned char	*stmp;
	size_t			n2;

	n2 = 0;
	dtmp = (unsigned char *)dest;
	stmp = (unsigned char *)src;
	while (n > 0 && *stmp != (unsigned char)c)
	{
		*dtmp++ = *stmp++;
		n--;
	}
	if (n > 0)
	{
		*dtmp++ = *stmp++;
		return ((unsigned char*)dtmp);
	}
	else
		return (NULL);
	return (0);
}
