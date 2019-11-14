/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:08:46 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:08:48 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_countwsstart(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static size_t	ft_countwsend(char const *s)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = ft_strlen(s) - 1;
	while (s[index] == ' ' || s[index] == '\t' || s[index] == '\n')
	{
		index--;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	blankstart;
	size_t	blankend;
	size_t	lentocreate;
	char	*strim;
	size_t	i;

	NULL_CHECK(s);
	blankstart = ft_countwsstart(s);
	blankend = ft_countwsend(s);
	lentocreate = ft_strlen(s) - blankstart - blankend;
	if (blankstart == 0 || blankend == 0)
		if ((strim = ft_strdup(s)) == NULL)
			return (NULL);
	if (ft_strlen(s) <= blankstart)
		return (strim = ft_strdup(""));
	if ((strim = ft_strnew(lentocreate)) == NULL)
		return (NULL);
	i = 0;
	while (i < lentocreate)
	{
		strim[i] = s[blankstart + i];
		i++;
	}
	return (strim);
}
