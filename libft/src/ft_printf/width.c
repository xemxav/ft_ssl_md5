/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   width.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/03 12:08:30 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		find_len(t_result *result, char *fl, t_infos *infos)
{
	int			fl_len;

	fl_len = 0;
	if (result->res_pres != NULL && (infos->convletter != 'c'
		&& infos->convletter != 'C'))
		result->res_size = ft_strlen(result->res_pres);
	if (fl != NULL)
		fl_len = ft_strlen(fl);
	return (result->res_size + fl_len);
}

static char		*my_join(char *first, char *second)
{
	if (first == NULL && second == NULL)
		return (NULL);
	if (first == NULL)
		return (ft_strdup(second));
	else if (second == NULL)
		return (ft_strdup(first));
	return (ft_strjoin(first, second));
}

static char		*join_three(char *s1, char *s2, char *s3, t_result *result)
{
	char		*tmp;

	tmp = NULL;
	tmp = my_join(s1, s2);
	result->res_width = my_join(tmp, s3);
	if (tmp != NULL)
		ft_strdel(&tmp);
	return (result->res_width);
}

static char		*put_width(char *fl, t_result *result, t_infos *infos, int len)
{
	char		*width;
	int			w_len;

	width = NULL;
	w_len = infos->width - len;
	width = ft_strnew(w_len);
	if (infos->zero == 1)
		width = ft_memset(width, '0', w_len);
	else
		width = ft_memset(width, ' ', w_len);
	if (infos->minus)
		result->res_width = join_three(fl, result->res_pres, width, result);
	else
	{
		if (infos->zero)
			result->res_width = join_three(fl, width, result->res_pres, result);
		else
			result->res_width = join_three(width, fl, result->res_pres, result);
	}
	ft_strdel(&width);
	return (result->res_width);
}

char			*make_width(t_infos *infos, t_result *result)
{
	char		*fl;
	int			len;

	if (ft_strchr(CHR, infos->convletter) != NULL)
		return (result->res_width = width_for_chr(infos, result));
	fl = make_flags(infos, result);
	len = find_len(result, fl, infos);
	if (infos->width < 0 || infos->width <= len)
	{
		if (fl != NULL)
		{
			result->res_width = my_join(fl, result->res_pres);
			ft_strdel(&fl);
			return (result->res_width);
		}
		if (fl == NULL && result->res_size != 0)
			return (ft_strdup(result->res_pres));
		if (fl == NULL && result->res_size == 0)
			return (NULL);
	}
	result->res_width = put_width(fl, result, infos, len);
	if (fl != NULL)
		ft_strdel(&fl);
	return (result->res_width);
}
