/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usages.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xem <xem@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:59:38 by xmoreau           #+#    #+#             */
/*   Updated: 2020/08/18 11:46:57 by xem              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ssl.h"

int					need_arg_usage(char *hash, char c)
{
	fd_printf(2, "ft_ssl: %s: option requires an argument -- %c\n",
			hash, c);
	fd_printf(2, "usage: %s [-pqr] [-s string] [files ...]\n", hash);
	return (ERROR);
}

int					md5_sha256_usage(char *hash, char c, char *filename,
		char *dirname)
{
	if (filename)
		fd_printf(2, "ft_ssl: %s: %s: No such file or directory\n"
				, hash, filename);
	else if (c)
	{
		fd_printf(2, "ft_ssl: %s: illegal option -- %c\n", hash, c);
		fd_printf(2, "usage: %s [-pqr] [-s string] [files ...]\n", hash);
	}
	else if (dirname)
		fd_printf(2, "%s: %s: Is a directory\n", hash, dirname);
	return (ERROR);
}

int					usage(char *bad_arg)
{
	if (bad_arg == NULL)
		fd_printf(2, "usage: ft_ssl command [command opts] [command args]\n");
	else
	{
		fd_printf(2, "ft_ssl: Error: '%s' is an invalid command.\n", bad_arg);
		fd_printf(2, "\nStandard commands:\n");
		fd_printf(2, "\nMessage digest commands:\nmd5\nsha256\n");
		fd_printf(2, "\nCipher commands:\n");
	}
	return (-1);
}
