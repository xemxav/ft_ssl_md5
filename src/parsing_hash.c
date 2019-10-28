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

int					md5_sha256_usage(char *hash, char c, char *filename)
{
	if (filename)
		ft_printf("%s: %s: No such file or directory\n", hash, filename);
	else
	{
		ft_printf("%s: illegal option -- %c\n", hash, c);
		ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", hash);
	}
	return (-1);
}

static int			make_s_flag(t_control *control, char *arg, size_t i)
{
	control->type = STRING;
	if (i + 1 < ft_strlen(arg))
	{
		control->message = (arg + i + 1);
		printf("arg+ i = %s\n", arg + i + 1); //todo : a effacer
		return (process_argument(control));
	}
	return (1);
}

static int			make_p_flag(t_control *control)
{
	control->p = 1;
	control->type = STDIN;
	if (!process_argument(control))
		return (-1);
	return (1);
}

static int			read_flags(t_control *control, char *arg)
{
	size_t			i;

	i = 1;
	while (i < ft_strlen(arg))
	{
		if (!ft_strchr(AUTHFLAGS, arg[i]))
			return (md5_sha256_usage(control->hash, arg[i], NULL));
		if (arg[i] == 'q')
			control->q = 1;
		if (arg[i] == 'r')
			control->r = 1;
		if (arg[i] == 'p')
		{
			if (make_p_flag(control) < 0)
				return (-1);
		}
		if (arg[i] == 's')
			return (make_s_flag(control, arg, i));
		i++;
	}
	return (1);
}

int					parsing(t_control *control, int ac, char **av)
{
	int				i;

	i = 2;
	while (i < ac)
	{
		if (av[i][0] == '-' && !control->file_only)
		{
			if ((read_flags(control, av[i])) < 0)
				return (-1);
		}
		else
		{
			control->message = av[i];
			if (!process_argument(control))
				return (-1);
		}
		i++;
	}
	if (!control->has_worked)
	{
		control->type = STDIN;
		return (process_argument(control));
	}
	return (0);
}
