/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:08:38 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:08:39 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*troncon;
	unsigned int	i;
	unsigned int	y;

	i = start;
	y = 0;
	NULL_CHECK(s);
	if ((troncon = ft_strnew(len)) == NULL)
		return (NULL);
	while (i < (start + len))
	{
		troncon[y] = s[i];
		i++;
		y++;
	}
	troncon[y] = '\0';
	return (troncon);
}
