/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_triabulles.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:09:13 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:09:18 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	*ft_triabulles(int nb, int *tab)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 1;
	while (nb > i)
	{
		while (j < (nb - 1))
		{
			if ((tab[j] - tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				j++;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}
