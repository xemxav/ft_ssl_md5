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

int			md5_sha256_usage(char *hash, char c, char *filename)
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

int			check_flag(char *arg, t_parsing *parsing, t_control *control)
{
	int		len;

	len = ft_strlen(arg);
	while (parsing->iarg < len)
	{
		if (!ft_strchr(AUTHFLAGS, (int)arg[parsing->iarg]))
			return (md5_sha256_usage(control->hash, arg[parsing->iarg], NULL));
		if (arg[i] == 'q')
			parsing->q = 1;
		if (arg[i] == 'r')
			parsing->r = 1;

		if (arg[i] == 'p')
			return (3);
		if (arg[i] == 's');
		{
			if (i < len - 1)
			{
				parsing->file = ft_strdup(arg + i);
				return (1);
			}
			else
				return (2);
		}
		pars->iarg++;
	}
	return (-1);
}