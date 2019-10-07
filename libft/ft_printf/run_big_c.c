/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   run_big_c.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/06 14:11:06 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_bytes_bigc(wint_t c)
{
	if (MB_CUR_MAX == 1 && c > 255)
		return (-1);
	if (c < 0)
		return (-1);
	if (c >= 0xd800 && c <= 0xDFFF)
		return (-1);
	if (c <= 0x7F || MB_CUR_MAX == 1)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (-1);
}

char			*create_mini_str(wint_t c, int byte)
{
	char		*str;

	str = ft_memalloc(byte);
	if (byte == 1)
		str[0] = c;
	if (byte == 2)
	{
		str[1] = (c & 0x3F) | 0x80;
		str[0] = ((c >> 6) | 0xC0);
	}
	if (byte == 3)
	{
		str[2] = ((c & 0x3F) | 0x80);
		str[1] = (((c >> 6) & 0x3F) | 0x80);
		str[0] = ((c >> 12) | 0xE0);
	}
	if (byte == 4)
	{
		str[3] = ((c & 0x3F) | 0x80);
		str[2] = (((c >> 6) & 0x3F) | 0x80);
		str[1] = (((c >> 12) & 0x3F) | 0x80);
		str[0] = ((c >> 18) | 0xF0);
	}
	return (str);
}

char			*make_lchr(wint_t c, t_infos *infos, t_result *result)
{
	int			byte;

	if ((byte = check_bytes_bigc(c)) == -1)
	{
		result->no_write = 1;
		infos->precision = -1;
		result->error = -1;
		return (NULL);
	}
	result->res_size = byte;
	return (create_mini_str(c, byte));
}
