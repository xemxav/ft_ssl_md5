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
	if (control->message != NULL)
		free(control->message);
	if (control->filename != NULL)
}