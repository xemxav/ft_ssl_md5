/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   processing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 14:02:23 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*run_p(va_list ap, t_infos *infos)
{
	char			*str;

	str = itoa_base_u((unsigned long)va_arg(ap, void*), 16);
	infos->hash = 1;
	return (str);
}

static char			*run_str(t_infos *infos, va_list ap, t_result *result)
{
	if (infos->h)
		return (make_str((char *)va_arg(ap, char *)));
	if (infos->l || infos->convletter == 'S')
		return (make_lstr((wchar_t*)va_arg(ap, wchar_t*), result, infos));
	return (make_str((char *)va_arg(ap, char *)));
}

static char			*run_chr(t_infos *infos, va_list ap, t_result *result)
{
	if (infos->h)
		return (make_chr((unsigned char)va_arg(ap, int), infos, result));
	if (infos->l || infos->convletter == 'C')
		return (make_lchr((wint_t)va_arg(ap, wint_t), infos, result));
	return (make_chr((unsigned char)va_arg(ap, int), infos, result));
}

char				*find_tree(t_infos *infos, va_list ap, t_result *result)
{
	if (infos->convletter == '%')
		return (ft_strdup("%"));
	else if (ft_strchr(UNSIGNED, infos->convletter) != NULL)
		return (run_unsigned(infos, ap));
	else if (ft_strchr(SIGNED, infos->convletter) != NULL)
		return (run_signed(infos, ap));
	else if (infos->convletter == 'p')
		return (run_p(ap, infos));
	else if (ft_strchr(STR, infos->convletter) != NULL)
		return (run_str(infos, ap, result));
	else if (ft_strchr(CHR, infos->convletter) != NULL)
		return (run_chr(infos, ap, result));
	else if (infos->convletter == 'a')
	{
		infos->convletter = '0';
		return (ft_strsub(result->flags, ft_strlen(result->flags) - 1, 1));
	}
	return (NULL);
}
