/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 14:01:36 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 11:28:54 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_list	*ft_multi_fd(t_list **file, int fd)
{
	t_list		*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	ft_lstadd(file, tmp);
	tmp->content_size = fd;
	tmp = *file;
	return (tmp);
}

static int		ft_alloc(t_list *actual, char **line, char c)
{
	size_t		len;
	char		*bn;

	if (c == 1)
	{
		bn = ft_strchr((char*)actual->content, '\n');
		len = ft_strlen(bn);
		if ((*line = ft_strsub((char*)actual->content, 0,
			(size_t)(bn - (char*)actual->content))) == NULL)
			return (-1);
		ft_memmove((char*)actual->content, bn + 1, len);
		if ((char*)actual->content == NULL)
			return (-1);
	}
	else
	{
		if ((*line = ft_strdup((char*)actual->content)) == NULL)
			return (-1);
		ft_bzero(actual->content, ft_strlen(actual->content));
	}
	return (1);
}

static char		*ft_myjoin(t_list *actual, char *buff)
{
	char		*joined;
	char		*tmp;

	tmp = ft_strdup((char*)actual->content);
	free((char*)actual->content);
	joined = ft_strjoin(tmp, buff);
	free(tmp);
	return (joined);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*file = NULL;
	t_list			*actual;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !(line) || (ret = read(fd, buff, 0)) < 0)
		return (-1);
	actual = ft_multi_fd(&file, fd);
	if (ft_strlen((char*)actual->content) != 0
	&& ft_strchr((char*)actual->content, '\n') != NULL)
		return (ft_alloc(actual, line, 1));
	while ((ret = read(actual->content_size, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		actual->content = ft_myjoin(actual, buff);
		if ((ft_strchr((char*)actual->content, '\n')) != NULL)
			return (ft_alloc(actual, line, 1));
	}
	if (ft_strlen((char*)actual->content) != 0)
		return (ft_alloc(actual, line, 0));
	if (ret == 0 && ft_strlen((char*)actual->content) == 0)
		return (0);
	return (1);
}
