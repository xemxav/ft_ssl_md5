/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi_split.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xem <xem@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 12:47:01 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 17:16:24 by xem         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_words(char const *s, char *c)
{
	int		x;
	int		ret;

	x = 0;
	if (!s)
		return (0);
	ret = 0;
	if (ft_strchr(c, s[0]) == NULL)
		ret = 1;
	while (s[x] != '\0')
	{
		if (s[x] == '\0')
			break ;
		if (s[x + 1] != '\0' && ft_strchr(c, s[x]) && !(ft_strchr(c, s[x + 1])))
			ret++;
		x++;
	}
	return (ret);
}

char		**multi_split(char const *s, char *c)
{
	char	**ret;
	int		nb_words;
	int		start;
	int		end;

	nb_words = count_words(s, c);
	if (!s || !(ret = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	end = ft_strlen(s) - 1;
	ret[nb_words] = NULL;
	while (nb_words)
	{
		while (end >= 0 && ft_strchr(c, s[end]))
			end--;
		start = end;
		while (start >= 0 && !(ft_strchr(c, s[start])))
			start--;
		ret[nb_words - 1] = ft_strsub(s, start + 1, end - start);
		end = start;
		nb_words--;
	}
	return (ret);
}
