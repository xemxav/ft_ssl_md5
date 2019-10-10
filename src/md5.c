/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:30:03 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 17:30:03 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"


int				md5(t_control *control)
{
	if (control->type == FILE)
		control->file_only = 1;
	ft_printf("control->hash = %s\n", control->hash);
	ft_printf("control->message = %s\n", control->message);
	ft_printf("control->p = %d\n", control->p);
	ft_printf("control->q = %d\n", control->q);
	ft_printf("control->r = %d\n", control->r);
	ft_printf("control->file_only = %d\n", control->file_only);
	ft_printf("control->type = %d\n\n", control->type);
	reset_control(control);
	return (1);
}