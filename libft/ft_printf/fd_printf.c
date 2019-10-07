/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fd_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/14 14:41:06 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				fd_printf(int fd, const char *fmt, ...)
{
	va_list		ap;
	t_toprint	to_print;

	to_print.print_size = 0;
	to_print.printed = NULL;
	va_start(ap, fmt);
	if (parsing_pf(fmt, ap, &to_print) == -1)
	{
		if (to_print.print_size != 0)
			write(fd, to_print.printed, to_print.print_size);
		if (to_print.printed != NULL)
			ft_strdel(&to_print.printed);
		return (-1);
	}
	va_end(ap);
	write(fd, to_print.printed, to_print.print_size);
	if (to_print.printed != NULL)
		ft_strdel(&to_print.printed);
	return (to_print.print_size);
}
