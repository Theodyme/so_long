/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:29:21 by flplace           #+#    #+#             */
/*   Updated: 2021/11/21 15:44:20 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str || !c)
		return (-1);
	i = 0;
	c = (char)c;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_lstsize(t_list *lst)
{
	int		ct;

	ct = 0;
	while (lst)
	{
		ct++;
		lst = lst->next;
	}
	return (ct);
}

char	*ft_strcat(char *dst, char *src, char c)
{
	while (*src && *src != c)
	{
		*dst++ = *src++;
	}
	*dst++ = *src++;
	if (c)
		*dst = '\0';
	return (dst - 1);
}

t_list	*ft_free_and_next(t_list *buf)
{
	t_list	*tmp;

	tmp = buf->next;
	free(buf);
	return (tmp);
}
