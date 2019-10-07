/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:03:55 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:03:57 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	if (csrc < cdest)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
		ft_memcpy(cdest, csrc, n);
	return (cdest);
}
