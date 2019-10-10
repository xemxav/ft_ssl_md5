/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   freeing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:15:19 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 17:15:19 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	free_control(t_control *control)
{
	if (control->hash != NULL)
		free(control->hash);
}

void	reset_control(t_control *control)
{
	if (control->message != NULL)
		control->message = NULL;
	control->p = 0;
	control->type = 0;
}