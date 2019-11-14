/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_management.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 17:11:48 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			init_infos(t_infos *infos)
{
	infos->hash = 0;
	infos->zero = 0;
	infos->minus = 0;
	infos->space = 0;
	infos->plus = 0;
	infos->hh = 0;
	infos->h = 0;
	infos->l = 0;
	infos->ll = 0;
	infos->j = 0;
	infos->z = 0;
	infos->width = -1;
	infos->precision = -1;
	infos->convletter = 'a';
}

void			init_result(t_result *result)
{
	result->res_size = 0;
	result->fl_size = 0;
	result->res = NULL;
	result->res_pres = NULL;
	result->res_width = NULL;
	result->flags = NULL;
	result->no_write = 0;
	result->error = 0;
}

void			free_result(t_result *result)
{
	ft_strdel(&(result->res));
	ft_strdel(&(result->res_pres));
	ft_strdel(&(result->res_width));
	ft_strdel(&(result->flags));
}

void			free_infos(t_infos *infos)
{
	ft_memdel((void**)&(infos));
}

void			flag_verif(t_infos *infos)
{
	if (infos->space == 1 && infos->plus == 1)
		infos->space = 0;
	if (infos->zero == 1 && infos->minus == 1)
		infos->zero = 0;
	if (infos->zero == 1 && infos->precision >= 0
	&& ft_strchr(NBRS, infos->convletter) != NULL)
		infos->zero = 0;
	if (infos->space == 1 && ft_strchr(SIGNED, infos->convletter) == NULL)
		infos->space = 0;
	if (infos->hash == 1 && ft_strchr(UNSIGNED, infos->convletter) == NULL)
		infos->hash = 0;
	if (infos->plus == 1 && ft_strchr(SIGNED, infos->convletter) == NULL)
		infos->plus = 0;
}
