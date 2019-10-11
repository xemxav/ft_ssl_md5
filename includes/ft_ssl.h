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

# define STDIN 1
# define FILE 0
# define STRING 2

typedef struct			s_control
{
	int					(*cmd)(struct s_control *);
	char				*hash;
	char 				*message;
	int					p;
	int 				q;
	int 				r;
	int					file_only;
	int					type;
	int 				has_worked;
	unsigned int		buf[16];
	ssize_t				size;
}						t_control;

/*
**		ft_ssl.c
*/
/*
**		freeing.c
*/
void			free_control(t_control *control);
void			reset_control(t_control *control);
/*
**		md5.c
*/
int				md5(t_control *control);
/*
**		sha256.c
*/
int				sha256(t_control *control);
/*
**		parsing_hash.c
*/
int				md5_sha256_usage(char *hash, char c, char *filename);
int 			parsing(t_control *control, int ac, char **av);
/*
**		debug.c
*/
void			print_control(t_control *control);
#endif
