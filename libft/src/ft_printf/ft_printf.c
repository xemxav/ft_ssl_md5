/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:40:52 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			join_result(t_toprint *to_print, t_result *result)
{
	char		*tmp;

	if (to_print->printed == NULL)
	{
		to_print->printed = ft_memalloc(result->res_size);
		to_print->printed =
		ft_memcpy(to_print->printed, result->res_width, result->res_size);
	}
	else
	{
		tmp = ft_memalloc(to_print->print_size);
		tmp = ft_memcpy(tmp, to_print->printed, to_print->print_size);
		ft_strdel(&to_print->printed);
		to_print->printed =
		ft_memalloc(to_print->print_size + result->res_size);
		to_print->printed =
		ft_memcpy(to_print->printed, tmp, to_print->print_size);
		ft_memmove(to_print->printed + to_print->print_size,
		result->res_width, result->res_size);
		ft_strdel(&tmp);
	}
	to_print->print_size += result->res_size;
}

void			join_buffer(const char *fmt, t_toprint *to_print,
				int start, int i)
{
	char		*tmp;
	int			len;

	len = i - start;
	if (i == 0)
		return ;
	if (to_print->printed == NULL)
	{
		to_print->printed = ft_memalloc(len);
		to_print->printed = ft_memcpy(to_print->printed, fmt + start, len);
	}
	else
	{
		tmp = ft_memalloc(to_print->print_size);
		tmp = ft_memcpy(tmp, to_print->printed, to_print->print_size);
		ft_strdel(&to_print->printed);
		to_print->printed = ft_memalloc(to_print->print_size + len);
		to_print->printed =
		ft_memcpy(to_print->printed, tmp, to_print->print_size);
		ft_memmove(to_print->printed + to_print->print_size, fmt + start, len);
		ft_strdel(&tmp);
	}
	to_print->print_size += len;
}

int				outcome(t_result *result, const char *fmt, int i, va_list ap)
{
	init_result(result);
	start_processing(fmt + i + 1, ap, result);
	if (result->error == -1)
	{
		free_result(result);
		return (-1);
	}
	return (0);
}

int				parsing_pf(const char *fmt, va_list ap, t_toprint *to_print)
{
	int			i;
	int			start;
	t_result	result;

	i = 0;
	start = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			if (outcome(&result, fmt, i, ap) == -1)
				return (-1);
			join_buffer(fmt, to_print, start, i);
			join_result(to_print, &result);
			free_result(&result);
			i += result.fl_size + 1;
			start = i;
		}
		else
			i++;
	}
	if ((i - start) != 0)
		join_buffer(fmt, to_print, start, i);
	return (0);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_toprint	to_print;

	to_print.print_size = 0;
	to_print.printed = NULL;
	va_start(ap, fmt);
	if (parsing_pf(fmt, ap, &to_print) == -1)
	{
		if (to_print.print_size != 0)
			write(1, to_print.printed, to_print.print_size);
		if (to_print.printed != NULL)
			ft_strdel(&to_print.printed);
		return (-1);
	}
	va_end(ap);
	write(1, to_print.printed, to_print.print_size);
	if (to_print.printed != NULL)
		ft_strdel(&to_print.printed);
	return (to_print.print_size);
}
