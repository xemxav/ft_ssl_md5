/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:07:21 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:07:23 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*snew;

	i = 0;
	snew = NULL;
	if (!s)
		return (NULL);
	if (s)
	{
		if ((snew = (char*)ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (i < ft_strlen(s))
		{
			snew[i] = (*f)(i, s[i]);
			i++;
		}
	}
	snew[i] = '\0';
	return (snew);
}
