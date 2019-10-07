/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   width_for_chr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 16:54:00 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*concat_str(char *s1, int l1, char *s2, int l2)
{
	char	*str;

	str = ft_memalloc(l1 + l2);
	str = ft_memcpy(str, s1, l1);
	ft_memmove(str + l1, s2, l2);
	return (str);
}

char			*width_for_chr(t_infos *infos, t_result *result)
{
	int			w_len;
	char		*width;
	char		*str;

	w_len = infos->width - result->res_size;
	if (infos->width < 0 || infos->width <= result->res_size)
		return (memdupsub(result->res_pres, 0, result->res_size));
	width = ft_memalloc(w_len);
	if (infos->zero == 1)
		width = ft_memset(width, '0', w_len);
	else
		width = ft_memset(width, ' ', w_len);
	if (infos->minus)
		str = concat_str(result->res_pres, result->res_size, width, w_len);
	else
		str = concat_str(width, w_len, result->res_pres, result->res_size);
	result->res_size += w_len;
	ft_strdel(&width);
	return (str);
}
