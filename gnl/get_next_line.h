/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:30:20 by flplace           #+#    #+#             */
/*   Updated: 2022/06/10 16:26:58 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 50

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

ssize_t		ft_lstaddnread(int fd, t_list **lst, int *idx, t_list **last);
int			ft_lstsize(t_list *lst);
int			ft_strchr(char *str, char c);
char		*ft_lstjoin(t_list **lst);
char		*get_next_line(int fd);
t_list		*ft_lstclear(t_list *buf, int idx);
char		*ft_strcat(char *dst, char *src, char c);
t_list		*ft_free_and_next(t_list *buf);

#endif
