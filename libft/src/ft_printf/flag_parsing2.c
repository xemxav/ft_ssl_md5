/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_parsing2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 15:43:02 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		get_flag(char c, t_infos *infos)
{
	if (c == '#')
		infos->hash = 1;
	if (c == '0')
		infos->zero = 1;
	if (c == '-')
		infos->minus = 1;
	if (c == '+')
		infos->plus = 1;
	if (c == ' ')
		infos->space = 1;
}

static int		find_width(char *flags, t_infos *infos, int i, va_list ap)
{
	if (flags[i] == '*')
	{
		infos->width = va_arg(ap, int);
		if (infos->width < 0)
		{
			infos->minus = 1;
			infos->width *= -1;
		}
		return (i + 1);
	}
	infos->width = ft_atoi(flags + i);
	while (ft_isdigit(flags[i]))
		i++;
	return (i);
}

static int		find_precision(char *flags, t_infos *infos, int i, va_list ap)
{
	if (infos->precision == -1)
	{
		if (flags[i] == '*')
		{
			infos->precision = va_arg(ap, int);
			return (i + 1);
		}
		if (!ft_isdigit(flags[i]))
			infos->precision = 0;
		if ((infos->precision = ft_atoi(flags + i)) < 0)
			infos->precision = 0;
	}
	while (ft_isdigit(flags[i]))
		i++;
	return (i);
}

static int		find_length(char *flags, t_infos *infos, int i)
{
	if (flags[i] == 'h')
	{
		if (flags[i + 1] == 'h')
		{
			infos->hh = 1;
			return (1);
		}
		else
			infos->h = 1;
	}
	else if (flags[i] == 'l')
	{
		if (flags[i + 1] == 'l')
		{
			infos->ll = 1;
			return (1);
		}
		else
			infos->l = 1;
	}
	else if (flags[i] == 'j')
		infos->j = 1;
	else if (flags[i] == 'z')
		infos->z = 1;
	return (0);
}

void			fill_struct(char *flags, t_infos *infos, va_list ap)
{
	int			i;

	i = 0;
	init_infos(infos);
	while (flags[i] != '\0')
	{
		if (ft_strchr(FLAGS, flags[i]) != NULL)
			get_flag(flags[i], infos);
		if ((ft_isdigit(flags[i]) == 1 && flags[i] != '0') || flags[i] == '*')
			i = find_width(flags, infos, i, ap) - 1;
		if (flags[i] == '.')
			i = find_precision(flags, infos, i + 1, ap) - 1;
		if ((ft_strchr(LENGTH, flags[i])) != NULL)
			i += find_length(flags, infos, i);
		if (ft_strchr(CONVERSION, flags[i]) != NULL)
			infos->convletter = flags[i];
		i++;
	}
	flag_verif(infos);
}
