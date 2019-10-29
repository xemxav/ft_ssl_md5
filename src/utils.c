/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 09:47:19 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 09:47:19 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int		rightrotate(unsigned int n, unsigned int d)
{
	 return ((n >> d) | (n << (32 - d)));
}

unsigned int		lefttrotate(unsigned int n, unsigned int d)
{
	return ((n << d) | (n >> (32 - d)));
}

void				*ft_memrev(void *block, size_t elsize, size_t elnum)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *) malloc(sizeof(unsigned char) * elsize);
	if (!tmp)
		return (NULL);
	while (i <= elnum - 1)
	{
		ft_memmove(tmp, block + (elsize * (elnum - 1)), elsize);
		ft_memmove(block + (elsize * (elnum - 1)),
		block + (i * elsize), elsize);
		ft_memmove(block + (i * elsize), tmp, elsize);
		elnum--;
		ft_bzero((void *) tmp, sizeof(unsigned char) * elsize);
		i++;
	}
	free(tmp);
	return (block);
}
