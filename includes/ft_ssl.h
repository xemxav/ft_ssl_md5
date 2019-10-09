/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 10:34:38 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 10:34:38 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

# include "../libft/libft.h"

# define AUTHFLAGS "pqrs"

typedef struct		s_parsing
{
	int				iac;
	int				iarg;
	char			s;
	char			r;
	char 			q;
	char 			p;
	char			*file;
}					t_parsing;

typedef struct		s_control
{
	int				(*cmd)(struct s_control *, int ac, char **av);
	char			*hash;
	char			*message;
	char			*filename;
	int 			fd;
}					t_control;

/*
**		ft_ssl.c
*/
/*
**		freeing.c
*/
void			free_control(t_control *control);
/*
**		md5.c
*/
int				md5(t_control *control, int ac, char **av);
/*
**		sha256.c
*/
int				sha256(t_control *control, int ac, char **av);
/*
**		parsing_hash.c
*/
int			check_flag(char *arg, t_parsing *parsing);
int			md5_sha256_usage(char *hash, char c, char *filename);

#endif
