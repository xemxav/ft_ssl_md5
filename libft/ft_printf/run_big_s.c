/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   run_big_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 13:19:21 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 16:46:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*create_mini_str2(wint_t c, int byte)
{
	char		*str;

	str = ft_strnew(byte);
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

static int		test_precision(wchar_t *lstr, t_infos *infos)
{
	int			i;
	int			b;
	int			c;

	i = 0;
	b = 0;
	c = 0;
	while (lstr[i] != '\0')
	{
		if ((b = check_bytes_bigc(lstr[i])) == -1)
		{
			if (c == infos->precision)
				return (i);
			if (c < infos->precision)
				return (-1);
		}
		c += b;
		if (c <= infos->precision)
			i++;
		else
			return (i);
	}
	return (i);
}

static int		get_nb_chr(wchar_t *lstr, t_infos *infos)
{
	int			i;
	int			b;

	i = 0;
	b = 0;
	if (infos->precision == -1)
	{
		while (lstr[i] != '\0')
		{
			if ((b = check_bytes_bigc(lstr[i])) == -1)
				return (-1);
			i++;
		}
	}
	else
		i = test_precision(lstr, infos);
	return (i);
}

static	char	*concat_char(wchar_t *lstr, int lstrlen, int i, int b)
{
	char		*tmp;
	char		*tmp2;
	char		*str;

	tmp = NULL;
	tmp2 = NULL;
	str = NULL;
	while (i < lstrlen)
	{
		b = check_bytes_bigc(lstr[i]);
		tmp = create_mini_str2(lstr[i], b);
		if (str != NULL)
		{
			tmp2 = ft_strdup(str);
			ft_strdel(&str);
			str = ft_strjoin(tmp2, tmp);
			ft_strdel(&tmp2);
		}
		else
			str = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (str);
}

char			*make_lstr(wchar_t *lstr, t_result *result, t_infos *infos)
{
	int			lstrlen;
	int			i;
	int			b;

	i = 0;
	b = 0;
	if (lstr == NULL)
		return (ft_strdup("(null)"));
	if ((lstrlen = get_nb_chr(lstr, infos)) == 0)
		return (ft_strdup(""));
	if (lstrlen == -1)
	{
		result->no_write = 1;
		infos->precision = -1;
		result->error = -1;
		return (NULL);
	}
	infos->precision = -1;
	return (concat_char(lstr, lstrlen, i, b));
}
