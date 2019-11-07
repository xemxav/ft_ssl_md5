/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 13:21:18 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 13:21:18 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static int				usage(char *bad_arg)
{
	if (bad_arg == NULL)
		fd_printf(2, "usage: ft_ssl command [command opts] [command args])\n");
	else
	{
		fd_printf(2, "ft_ssl: Error: '%s' is an invalid command.\n", bad_arg);
		fd_printf(2, "\nStandard commands:\n");
		fd_printf(2, "\nMessage digest commands:\nmd5\nsha256\n");
		fd_printf(2, "\nCipher commands:\n");
	}
	return (-1);
}

const t_cmd g_cmd_tab[2] = {
		{"md5", "MD5", &parsing_hash, hash_md5_buf},
		{"sha256", "SHA256", &parsing_hash, hash_sha256_buf}
		};

static	t_cmd 			*parsing_cmd(char *av)
{
	int					i;

	i = 0;
	while (i < CMD_NB)
	{
		if (ft_strequ(av, g_cmd_tab[i].cmd_name))
		{
			return ((t_cmd*)&(g_cmd_tab[i]));
		}
		i++;
	}
	return (NULL);
}

int						main(int ac, char **av)
{
	t_cmd				*cmd;

	if (ac == 1)
		return (usage(NULL));
	if (!(cmd = parsing_cmd(av[1])))
		return (usage(av[1]));
	if (cmd->pars_func(cmd, ac, av) == ERROR)
		return (ERROR);
	return (TRUE);
}

//0123456789012345678901234567890123456789012345678901234567891234
//
//01234567890123456789012345678901234567890123456789012345678912345678