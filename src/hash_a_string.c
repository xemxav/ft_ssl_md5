/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hash_a_string.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 13:46:23 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 13:46:23 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int 			hash_a_string(t_control *control)
{
	size_t		len;

	if (control->end_message)
		return (1);
	len = ft_strlen(control->message);
	ft_memcpy(control->buf, control->message, len);
	control->size += len * 8;
	control->message += len;
	if (len < 64)
		padding(control, len % 4, (int)(len / 4));
	control->hash_func(control);
	return (hash_a_string(control));
}