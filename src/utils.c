/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 09:47:19 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 09:47:19 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int		rightrotate(unsigned int n, unsigned int d)
{
	return ((n >> d) | (n << (32 - d)));
}

unsigned int		lefttrotate(unsigned int n, unsigned int d)
{
	return ((n << d) | (n >> (32 - d)));
}

int					record_message(t_control *control, unsigned int i)
{
	void			*tmp;
	size_t			len;

	if (!control->message)
	{
		if (!(control->message = (char*)malloc(1)))
			return (ERROR);
		ft_memcpy((void*)control->message, (void*)control->buf, 1);
	}
	else
	{
		len = (size_t)(control->size / 8);
		if ((tmp = (void*)malloc(len - 1)) == NULL)
			return (ERROR);
		ft_memcpy(tmp, (void*)control->message, len - 1);
		free(control->message);
		if (!(control->message = (char*)malloc((size_t)len)))
			return (ERROR);
		ft_memcpy((void*)control->message, (void*)tmp, len - 1);
		ft_memcpy(control->message + (len - 1),
				(void*)control->buf + i, 1);
		free(tmp);
	}
	return (TRUE);
}

void				init_control(t_control *control, t_cmd *cmd)
{
	ft_bzero((void*)control, sizeof(t_control));
	control->hash_func = cmd->hash_func;
	control->hash = cmd->cmd_name;
	control->hash_maj = cmd->cmd_name_maj;
	control->reg_nb = cmd->reg_nb;
}
