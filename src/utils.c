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

void				*ft_memrev(void *block, size_t elsize, size_t elnum)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)malloc(sizeof(unsigned char) * elsize);
	if (!tmp)
		return (NULL);
	while (i <= elnum - 1)
	{
		ft_memmove(tmp, block + (elsize * (elnum - 1)), elsize);
		ft_memmove(block + (elsize * (elnum - 1)),
		block + (i * elsize), elsize);
		ft_memmove(block + (i * elsize), tmp, elsize);
		elnum--;
		ft_bzero((void *)tmp, sizeof(unsigned char) * elsize);
		i++;
	}
	free(tmp);
	return (block);
}

int					record_message(t_control *control, unsigned int i)
{
	char			*tmp;
	size_t			len;

	if (!control->message)
	{
		if (!(control->message = ft_strnew(1)))
			return (ERROR);
		ft_memcpy(control->message, control->buf + i, 1);
	}
	else
	{
		len = (size_t)(control->size / 8);
		tmp = ft_strdup(control->message);
		if (!tmp)
			return (ERROR);
		free(control->message);
		if (!(control->message = ft_strnew(len)))
			return (ERROR);
		ft_memcpy(control->message, tmp, len - 1);
		ft_memcpy(control->message + (len - 1),
				(unsigned char*)control->buf + i, 1);
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
