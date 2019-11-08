/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_hash.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:33:00 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 14:33:00 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static int			make_s_flag(t_control *control, char *arg, size_t i)
{
	control->type = STRING;
	if (i + 1 < ft_strlen(arg))
	{
		control->message = (arg + i + 1);
		return (process_argument(control));
	}
	return (TRUE);
}

static int			make_p_flag(t_control *control)
{
	control->p += 1;
	control->type = STDIN;
	return (process_argument(control));
}

static int			read_flags(t_control *control, char *arg)
{
	size_t			i;

	i = 1;
	while (i < ft_strlen(arg))
	{
		if (!ft_strchr(AUTHFLAGS, arg[i]))
			return (md5_sha256_usage(control->hash, arg[i], NULL, NULL));
		if (arg[i] == 'q')
			control->q = 1;
		if (arg[i] == 'r')
			control->r = 1;
		if (arg[i] == 'p')
		{
			if (make_p_flag(control) == ERROR)
				return (ERROR);
		}
		if (arg[i] == 's')
			return (make_s_flag(control, arg, i));
		i++;
	}
	return (TRUE);
}

int					check_argument(t_control *control, char **av, int i)
{
	if (av[i][0] == '-' && !control->file_only)
	{
		if ((read_flags(control, av[i])) == ERROR)
			return (ERROR);
	}
	else
	{
		control->message = av[i];
		if (process_argument(control) == ERROR)
			return (ERROR);
	}
	return (TRUE);
}

int					parsing_hash(t_cmd *cmd, int ac, char **av)
{
	int				i;
	t_control		control;

	i = 2;
	init_control(&control, cmd);
	while (i < ac)
	{
		if (check_argument(&control, av, i) == ERROR)
			return (ERROR);
		i++;
	}
	if (control.type == STRING)
		return (md5_sha256_usage(control.hash, 's', NULL, NULL));
	if (!control.has_worked)
	{
		control.type = STDIN;
		return (process_argument(&control));
	}
	return (TRUE);
}
