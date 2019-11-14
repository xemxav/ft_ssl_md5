/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:03:04 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:03:05 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*zm;

	zm = (void *)malloc(sizeof(zm) * size);
	if (zm == NULL)
		return (NULL);
	ft_memset(zm, 0, size);
	return ((void *)zm);
}
