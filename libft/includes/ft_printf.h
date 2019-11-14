/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xem <xem@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 10:23:15 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 17:09:13 by xem         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <limits.h>

# define ALL ".*#0-+ hlLjzsSpdDioOuUxXcCnbB%123456789"
# define FLAGS "#0-+ "
# define LENGTH "hlLjz"
# define CONVERSION "sSpdDioOuUxXcCnbB%"
# define STR "sS"
# define UNSIGNED "oOuUxXbB"
# define SIGNED "dDi"
# define CHR "cC"
# define LTRS "cCsS"
# define NBRS "oOuUxXdDibp0"
# define FORH "oOuUxX"

typedef struct	s_infos
{
	int			hash;
	int			zero;
	int			minus;
	int			space;
	int			plus;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			width;
	int			precision;
	int			convletter;
}				t_infos;

typedef struct	s_result
{
	int			res_size;
	char		*res;
	char		*res_pres;
	char		*res_width;
	char		*flags;
	int			fl_size;
	int			no_write;
	int			error;
}				t_result;

typedef struct	s_toprint
{
	int			print_size;
	char		*printed;
}				t_toprint;

int				ft_printf(const char *fmt, ...);
int				fd_printf(int fd, const char *fmt, ...);
int				parsing_pf(const char *fmt, va_list ap, t_toprint *to_print);
int				outcome(t_result *result, const char *fmt, int i, va_list ap);
void			join_buffer(const char *fmt, t_toprint *to_print,
				int start, int i);
void			join_result(t_toprint *to_print, t_result *result);
void			init_infos(t_infos *infos);
void			init_result(t_result *result);
void			free_result(t_result *result);
void			free_infos(t_infos *infos);
void			start_processing(const char *source, va_list ap,
				t_result *result);
char			*find_tree(t_infos *infos, va_list ap, t_result *result);
char			*run_signed(t_infos *infos, va_list ap);
char			*itoa_base_s(long long int n, int base);
char			*run_unsigned(t_infos *infos, va_list ap);
char			*itoa_base_u(unsigned long long int n, int base);
char			*make_chr(unsigned char c, t_infos *infos, t_result *result);
char			*make_lchr(wint_t c, t_infos *infos, t_result *result);
int				check_bytes_bigc(wint_t c);
char			*create_mini_str(wint_t c, int byte);
char			*make_lstr(wchar_t *lstr, t_result *result, t_infos *infos);
char			*make_str(char *s);
char			*make_precision(t_infos *infos, t_result *result);
char			*make_width(t_infos *infos, t_result *result);
char			*make_flags(t_infos *infos, t_result *result);
void			fill_struct(char *flags, t_infos *infos, va_list ap);
void			flag_verif(t_infos *infos);
char			*memdupsub(char *src, int start, int size);
char			*width_for_chr(t_infos *infos, t_result *result);
#endif
