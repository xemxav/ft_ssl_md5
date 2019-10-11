/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:30:12 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 17:30:12 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int			sha256(t_control *control)
{
	if (control->type == FILE)
		control->file_only = 1;
	control->has_worked = 1;
	print_control(control);
	reset_control(control);
	return (1);
}