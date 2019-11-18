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

static int			make_s_flag(t_control *control, char **av, size_t y, int *i)
{
	control->type = STRING;
	if (y + 1 < ft_strlen(av[*i]))
	{
		control->message = (av[*i] + y + 1);
		return (process_argument(control));
	}
	else
	{
		*i += 1;
		control->message = av[*i];
	}
	return (process_argument(control));
}

static int			make_p_flag(t_control *control)
{
	control->p += 1;
	control->type = STDIN;
	return (process_argument(control));
}

static int			read_flags(t_control *control, char **av, int *i)
{
	size_t			y;

	y = 1;
	while (y < ft_strlen(av[*i]))
	{
		if (!ft_strchr(AUTHFLAGS, av[*i][y]))
			return (md5_sha256_usage(control->hash, av[*i][y], NULL, NULL));
		if (av[*i][y] == 'q')
			control->q = 1;
		if (av[*i][y] == 'r')
			control->r = 1;
		if (av[*i][y] == 'p')
		{
			if (make_p_flag(control) == ERROR)
				return (ERROR);
		}
		if (av[*i][y] == 's')
			return (make_s_flag(control, av, y, i));
		i++;
	}
	return (TRUE);
}

int					check_argument(t_control *control, char **av, int *i)
{
	if (av[*i][0] == '-' && !control->file_only)
	{
		if ((read_flags(control, av, i)) == ERROR)
			return (ERROR);
	}
	else
	{
		control->message = av[*i];
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
		if (check_argument(&control, av, &i) == ERROR)
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
