/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_s_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 16:47:03 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*make_str(char *s)
{
	if (s == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

char		*make_chr(unsigned char c, t_infos *infos, t_result *result)
{
	char	*str;

	str = ft_memalloc(1);
	str[0] = c;
	result->res_size = 1;
	infos->precision = -1;
	return (str);
}
