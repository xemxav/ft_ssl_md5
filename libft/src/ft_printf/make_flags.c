/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_flags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 17:28:12 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char		*make_hash(t_infos *infos, t_result *result)
{
	if (infos->convletter == 'o' || infos->convletter == 'O')
	{
		if (result->res_pres != NULL && result->res_pres[0] == '0')
			return (NULL);
		return (ft_strdup("0"));
	}
	if (infos->convletter != 'p' && result->res_pres == NULL)
		return (NULL);
	if (infos->convletter == 'p')
		return (ft_strdup("0x"));
	if (result->res[0] == '0')
		return (NULL);
	if (infos->convletter == 'x')
		return (ft_strdup("0x"));
	if (infos->convletter == 'X')
		return (ft_strdup("0X"));
	if (infos->convletter == 'b')
		return (ft_strdup("0b"));
	if (infos->convletter == 'B')
		return (ft_strdup("0B"));
	return (NULL);
}

static char		*take_away_minus(t_result *result)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strsub(result->res_pres, 1, result->res_size - 1);
	ft_strdel(&(result->res_pres));
	result->res_pres = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (ft_strdup("-"));
}

static char		*make_plus(t_result *result)
{
	if (result->res_pres != NULL)
	{
		if (result->res_pres[0] == '-')
			return (take_away_minus(result));
	}
	return (ft_strdup("+"));
}

static void		make_big(t_result *result)
{
	int			i;

	i = 0;
	while (result->res_pres[i] != '\0')
	{
		result->res_pres[i] = ft_toupper(result->res_pres[i]);
		i++;
	}
}

char			*make_flags(t_infos *infos, t_result *result)
{
	if (result->res_pres != NULL)
		result->res_size = ft_strlen(result->res_pres);
	if (result->res_pres != NULL && infos->convletter == 'X')
		make_big(result);
	if (infos->hash == 1)
		return (make_hash(infos, result));
	if (infos->space == 1)
	{
		if (result->res_pres != NULL)
		{
			if (result->res_pres[0] == '-')
				return (NULL);
		}
		return (ft_strdup(" "));
	}
	if (infos->plus == 1)
		return (make_plus(result));
	if (result->res_size != 0 && result->res_pres[0] == '-')
		return (take_away_minus(result));
	return (NULL);
}
