/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:06:09 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:06:15 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*sdup;

	len = ft_strlen(s);
	sdup = ft_strnew(len);
	NULL_CHECK(sdup);
	sdup = (char*)ft_memcpy(sdup, s, len);
	return (sdup);
}
