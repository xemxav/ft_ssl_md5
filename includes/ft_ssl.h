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

typedef struct          s_md5_worker
{
    unsigned int        A;
    unsigned int        B;
    unsigned int        C;
    unsigned int        D;
    unsigned int        s[64];
    unsigned int        K[64];
}                       t_md5_worker;

typedef struct          s_sha_worker
{
    unsigned int        A;
    unsigned int        B;
    unsigned int        C;
    unsigned int        D;
    unsigned int        E;
    unsigned int        F;
    unsigned int        G;
    unsigned int        H;
    unsigned int        w[64];
    unsigned int        K[64];
}                       t_sha_worker;

typedef struct          s_sha_temp
{
    unsigned int        S1;
    unsigned int        ch;
    unsigned int        temp1;
    unsigned int        S0;
    unsigned int        maj;
    unsigned int        temp2;
}                       t_sha_temp;

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
	ssize_t             byte_count;
	int					end_message;
	struct s_md5_worker *md5_worker;
    struct s_sha_worker *sha_worker;
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
void			hash_buf(t_control *control);
/*
**		init_md5_worker.c
*/
int            init_md5_worker(t_control *control);
/*
**		init_sha256_worker.c
*/
int            init_sha_worker(t_control *control);
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
void			print_buf(t_control *control);
/*
**		utils.c
*/
void                *ft_memrev(void *block, size_t elsize, size_t elnum);
unsigned int        rightrotate(unsigned int n, unsigned int d);
unsigned int        lefttrotate(unsigned int n, unsigned int d);

#endif
