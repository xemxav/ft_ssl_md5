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

typedef struct		s_control
{
	int				(*cmd)(struct s_control *);
//	char			*cmd;
	char			*message;
	char			*filename;
	char 			r;
	char 			q;
	char 			p;
	int 			fd;
}					t_control;


/*
**		ft_ssl.c
*/
/*
**		freeing.c
*/
/*
**		md5.c
*/
int				md5(t_control *control);
/*
**		sha256.c
*/
int				sha256(t_control *control);

#endif
