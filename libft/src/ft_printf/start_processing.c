/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   start_processing.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 10:43:01 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	get_flags(const char *s, t_result *result)
{
	int		i;

	i = 0;
	while (ft_strchr(ALL, s[i]) != NULL && s[i] != '\0')
	{
		if (ft_strchr(CONVERSION, s[i]) != NULL)
		{
			result->flags = ft_strsub(s, 0, i + 1);
			return (i + 1);
		}
		i++;
	}
	if (s[i] == '\0')
		return (i);
	result->flags = ft_strsub(s, 0, i + 1);
	return (i + 1);
}

void		start_processing(const char *source, va_list ap, t_result *result)
{
	t_infos	infos;

	result->fl_size = get_flags(source, result);
	if (result->flags == NULL)
		return ;
	fill_struct(result->flags, &infos, ap);
	if ((result->res = find_tree(&infos, ap, result)) == NULL)
	{
		result->res_size = 0;
		if (result->error == -1)
			return ;
	}
	if ((result->res_pres = make_precision(&infos, result)) == NULL)
		result->res_size = 0;
	if ((result->res_width = make_width(&infos, result)) == NULL)
	{
		result->res_size = 0;
		return ;
	}
	if (ft_strchr(CHR, infos.convletter) == NULL)
		result->res_size = ft_strlen(result->res_width);
}
