/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:06:50 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:06:53 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sconcat;
	size_t	len;
	int		i;
	int		y;

	i = 0;
	y = 0;
	NULL_CHECK(s1);
	NULL_CHECK(s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((sconcat = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		sconcat[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		sconcat[i + y] = s2[y];
		y++;
	}
	sconcat[i + y] = '\0';
	return (sconcat);
}
