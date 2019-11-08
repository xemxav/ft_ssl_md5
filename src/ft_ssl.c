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

const t_cmd g_cmd_tab[2] = {
	{"md5", "MD5", &parsing_hash, hash_md5_buf, 4},
	{"sha256", "SHA256", &parsing_hash, hash_sha256_buf, 8}
};

static	t_cmd			*parsing_cmd(char *av)
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
