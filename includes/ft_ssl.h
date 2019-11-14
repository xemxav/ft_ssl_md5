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

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>

# define CMD_NB			2

# define AUTHFLAGS "pqrs"

# define STDIN			1
# define FILE			0
# define STRING			2
# define TRUE			1
# define FALSE			0
# define ERROR			-1

# define REG_A			0
# define REG_B			1
# define REG_C			2
# define REG_D			3
# define REG_E			4
# define REG_F			5
# define REG_G			6
# define REG_H			7

typedef struct			s_h_worker
{
	unsigned int		reg[8];
	unsigned int		f_md5;
	unsigned int		index_md5;
	unsigned int		w_sha[64];
}						t_h_worker;

typedef struct			s_sha_temp
{
	unsigned int		s1;
	unsigned int		ch;
	unsigned int		temp1;
	unsigned int		s0;
	unsigned int		maj;
	unsigned int		temp2;
}						t_sha_temp;

typedef struct			s_control
{
	int					(*hash_func)(struct s_control *);
	char				*hash;
	char				*hash_maj;
	char				*message;
	int					p;
	int					q;
	int					r;
	int					file_only;
	int					type;
	size_t				str_len;
	int					has_worked;
	int					reg_nb;
	unsigned int		buf[16];
	ssize_t				size;
	int					end_message;
	struct s_h_worker	*worker;
}						t_control;

const unsigned int		g_k_md5[64];
const unsigned int		g_s_md5[64];
const unsigned int		g_k_sha[64];

typedef struct			s_cmd
{
	char				*cmd_name;
	char				*cmd_name_maj;
	int					(*pars_func)(struct s_cmd *, int, char **);
	int					(*hash_func)(struct s_control *);
	int					reg_nb;
}						t_cmd;

const t_cmd				g_cmd_tab[2];
/*
**		process_argument.c
*/
int						process_argument(t_control *control);
/*
**		print_digest.c
*/
void					print_result(t_control *control);
/*
**		freeing.c
*/
void					reset_control(t_control *control);
/*
**		md5.c
*/
int						hash_md5_buf(t_control *control);
/*
**		init_md5_worker.c
*/
int						init_w(t_h_worker *worker, unsigned int *buf);
int						init_md5_worker(t_control *control);
/*
**		init_sha256_worker.c
*/
int						init_sha_worker(t_control *control);
/*
**		sha256.c
*/
void					slave_serves_worker(t_h_worker *worker,
						t_h_worker *slave, int max_reg_ind);
int						hash_sha256_buf(t_control *control);
/*
**		parsing_hash.c
*/
int						parsing_hash(t_cmd *cmd, int ac, char **av);
/*
**		utils.c
*/
void					*ft_memrev(void *block, size_t elsize, size_t elnum);
unsigned int			rightrotate(unsigned int n, unsigned int d);
unsigned int			lefttrotate(unsigned int n, unsigned int d);
int						record_message(t_control *control, unsigned int i);
void					init_control(t_control *control, t_cmd *cmd);
/*
**		usages.c
*/
int						md5_sha256_usage(char *hash, char c, char *filename,
						char *dirname);
int						usage(char *bad_arg);
#endif
