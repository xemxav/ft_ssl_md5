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

void	reset_control(t_control *control)
{
	if (control->type == STDIN && control->p)
	{
		free(control->message);
		control->message = NULL;
	}
	if (control->message != NULL)
		control->message = NULL;
	control->type = 0;
	control->size = 0;
	control->str_len = 0;
	control->end_message = 0;
	if (control->worker)
	{
		free(control->worker);
		control->worker = NULL;
	}
}
