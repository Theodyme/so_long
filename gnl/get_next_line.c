/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:29:01 by flplace           #+#    #+#             */
/*   Updated: 2022/06/25 16:27:37 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lstjoin(t_list **buf)
{
	char	*s;
	char	*s_end;

	s = malloc(sizeof(char) * ((ft_lstsize(*buf) * BUFFER_SIZE) + 2));
	if (!s)
		return (NULL);
	s[0] = '\0';
	s_end = s;
	while ((*buf)->next)
	{
		s_end = ft_strcat(s_end, (*buf)->content, '\0');
		*buf = ft_free_and_next(*buf);
	}
	ft_strcat(s_end, (*buf)->content, '\n');
	if (ft_strchr((*buf)->content, '\n') == -1)
	{
		free(*buf);
		(*buf) = NULL;
	}
	return (s);
}

ssize_t	ft_lstaddnread(int fd, t_list **buf, int *idx, t_list **last)
{
	ssize_t		i;
	t_list		*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (-1);
	new->next = NULL;
	if (!(*buf))
		*buf = new;
	else
		(*last)->next = new;
	i = read(fd, new->content, BUFFER_SIZE);
	if (i == -1)
	{
		new->content[0] = '\0';
		return (i);
	}
	*last = new;
	new->content[i] = '\0';
	*idx = ft_strchr(new->content, '\n');
	return (i);
}

t_list	*ft_lstclear(t_list *buf, int idx)
{
	int	j;

	j = 0;
	if (buf == NULL)
		return (NULL);
	while (buf->content[idx])
		buf->content[j++] = buf->content[idx++];
	buf->content[j] = '\0';
	if (j == 0)
		return (ft_free_and_next(buf));
	buf->next = NULL;
	return (buf);
}

char	*handle_eof(char **line, t_list **buf)
{
	if ((*buf) && (*buf)->content[0] != '\0')
	{
		*line = ft_lstjoin(buf);
		free(*buf);
		*buf = NULL;
		return (*line);
	}
	while (*buf)
		*buf = ft_free_and_next(*buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list		*buf = NULL;
	char				*line;
	int					idx;
	ssize_t				i;
	t_list				*last;

	if (fd < 0)
		return (NULL);
	line = NULL;
	idx = -1;
	last = buf;
	if (buf)
		idx = ft_strchr(buf->content, '\n');
	while (idx == -1)
	{
		i = ft_lstaddnread(fd, &buf, &idx, &last);
		if (i == 0 || i == -1)
			return (handle_eof(&line, &buf));
		if (i < BUFFER_SIZE)
			break ;
	}
	line = ft_lstjoin(&buf);
	buf = ft_lstclear(buf, (idx + 1));
	return (line);
}
