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

static int 			usage(char	*bad_arg)
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

static int				parsing_cmd(char **av, t_control *control) {
	if (ft_strequ(av[1], "md5"))
	{
		control->hash_func = &hash_md5_buf;
		control->hash = ft_strdup("MD5");
	}
	else if (ft_strequ(av[1], "sha256"))
	{
		control->hash_func = &hash_sha256_buf;
		control->hash = ft_strdup("SHA256");
	}
	else
		return (usage(av[1]));
	return (1);
}

int				main(int ac, char **av)
{
	t_control	control;

	if (ac == 1)
		return (usage(NULL));
	ft_bzero(&control, sizeof(t_control));
	if (parsing_cmd(av, &control) < 0)
		return (-1);
	parsing(&control, ac, av);
	free_control(&control);
	return (0);
}