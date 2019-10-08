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

static int				analyse_av(int ac, char **av,
		t_control *control, int *i)
{
	if (*i >= ac)
		return (-1);
	if (ac == 1)
	{
		*i += 1;
		return (1);
	}
	if (ft_strequ(av[*i], "-p"))
		control->p = 1;
	else if (ft_strequ(av[*i], "-q"))
		control->q = 1;
	else if (ft_strequ(av[*i], "-r"))
		control->r = 1;
	else if (ft_strequ(av[*i], "-s"))
	{
		control->message = av[*i + 1];
		*i += 1;
		return (1);
	}
	else
	{
		control->filename = av[*i];
		return (1);
	}
	return (0);
}

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

static int				parsing_cmd(char **av, t_control *control)
{
	if (ft_strequ(av[1], "md5"))
		control->cmd = &md5;
	else if (ft_strequ(av[1], "sha256"))
		control->cmd = &sha256;
	else
		return (usage(av[1]));
	return (1);
}

int				main(int ac, char **av)
{
	t_control	control;
	int			i;
	int			c;

	i = 1;
	c = 0;
	if (ac == 1)
		return (usage(NULL));
	ft_bzero(&control, sizeof(t_control));
	if (parsing_cmd(av, &control) < 0)
		return (-1);
	while ((c = analyse_av(ac, av, &control, &i)) >= 0)
	{
		if (c == 1)
		{
			control.cmd(&control);
			control.fd = 0;
		}
		i++;
	}
	free(control.cmd);
	return (0);
}