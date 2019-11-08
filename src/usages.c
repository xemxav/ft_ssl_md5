/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   usages.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 15:59:38 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 15:59:38 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int					md5_sha256_usage(char *hash, char c, char *filename)
{
	if (filename)
	{
		fd_printf(2, "ft_ssl: %s: %s: No such file or directory\n"
				, hash, filename);
		return (ERROR);
	}
	else if (c)
	{
		fd_printf(2, "ft_ssl: %s: illegal option -- %c\n", hash, c);
		fd_printf(2, "usage: %s [-pqr] [-s string] [files ...]\n", hash);
	}
	else
	{
		fd_printf(2, "ft_ssl: %s: illegal option -- s\n", hash);
		fd_printf(2, "usage: %s [-pqr] [-s string] [files ...]\n", hash);
	}
	return (FALSE);
}

int					usage(char *bad_arg)
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