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

static int			usage(char *bad_arg)
{
	if (bad_arg == NULL)
		ft_printf("usage: ft_ssl command [command opts] [command args])\n");
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", bad_arg);
		ft_printf("\nStandard commands:\n");
		ft_printf("\nMessage digest commands:\nmd5\nsha256\n");
		ft_printf("\nCipher commands:\n");
	}
	return (-1);
}


//static int			parsing_cmd(char **av, t_cmd *cmd)
//{
//	if (ft_strequ(av[1], "md5"))
//	{
//		control->hash_func = &hash_md5_buf;
//		control->hash = av[1];
//	}
//	else if (ft_strequ(av[1], "sha256"))
//	{
//		control->hash_func = &hash_sha256_buf;
//		control->hash = av[1];
//	}
//	else
//		return (usage(av[1]));
//	return (1);
}

const t_cmd g_tab_struct[2] = {
		{"md5", &parsing_hash, hash_md5_buf, 4},
		{"sha256", &parsing_hash, hash_sha256_buf, 8}
		};

static	const t_cmd 		*parsing_cmd(char **av)
{
	int 			i;

	i = 0;
	while (i < CMD_NB)
	{
		if (ft_strequ(av[1], g_tab_struct[i].cmd_name))
		{
			return (&(g_tab_struct[i]));

		}
		i++;
	}
	return (NULL);
}

int						main(int ac, char **av)
{
	t_cmd	*cmd;

	if (ac == 1)
		return (usage(NULL));
	ft_bzero(&control, sizeof(t_control));
	if (!(cmd = parsing_cmd(av)))
		return (-1);
	cmd->pars_func(cmd, ac, av);
	return (0);
}
