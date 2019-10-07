/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   precision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/06 14:32:27 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char			*memdupsub(char *src, int start, int size)
{
	char		*str;

	str = ft_memalloc(size);
	str = ft_memcpy(str, src + start, size);
	return (str);
}

static void		make_concat(int len, t_result *result, int minus)
{
	char		*tmp;
	char		*tmp2;

	if (minus == 1)
	{
		tmp = ft_strnew((size_t)(len + 1));
		ft_memset(tmp, '0', (size_t)(len + 1));
		ft_memset(tmp, '-', 1);
		tmp2 = ft_strsub(result->res, 1, result->res_size - 1);
	}
	else
	{
		tmp = ft_strnew((size_t)len);
		ft_memset(tmp, '0', (size_t)len);
		tmp2 = ft_strdup(result->res);
	}
	result->res_pres = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

static void		prec_nbrs(t_infos *infos, t_result *result)
{
	int			len;
	int			nb_len;

	nb_len = result->res_size;
	if (result->res[0] == '-')
		nb_len--;
	if (infos->precision == 0 && result->res[0] == '0')
		return ;
	if (infos->precision <= (nb_len))
	{
		result->res_pres = ft_strdup(result->res);
		return ;
	}
	len = infos->precision - nb_len;
	if (result->res[0] == '-')
		make_concat(len, result, 1);
	else
		make_concat(len, result, 0);
}

static char		*prec_ltrs(t_infos *infos, t_result *result)
{
	if (infos->precision >= result->res_size)
		return (ft_strdup(result->res));
	return (ft_strsub(result->res, 0, infos->precision));
}

char			*make_precision(t_infos *infos, t_result *result)
{
	if (infos->convletter == 'a')
		return (NULL);
	if (infos->convletter != 'c' && infos->convletter != 'C')
		result->res_size = ft_strlen(result->res);
	if (infos->precision < 0 || infos->convletter == '%')
	{
		if (infos->convletter != 'c' && infos->convletter != 'C')
			return (ft_strdup(result->res));
		return (memdupsub(result->res, 0, result->res_size));
	}
	if (ft_strchr(LTRS, infos->convletter) != NULL)
		return (prec_ltrs(infos, result));
	if (ft_strchr(NBRS, infos->convletter) != NULL)
	{
		prec_nbrs(infos, result);
		return (result->res_pres);
	}
	return (NULL);
}
