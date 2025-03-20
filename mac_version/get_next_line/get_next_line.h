/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:12:15 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/01/24 22:57:48 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h> //read()
# include <fcntl.h> //open()
# include <stdlib.h> // malloc
# include <stdio.h> //printf

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		len_till_new_line(t_list *list);
void	copy_str(t_list *list, char *buf);
char	*get_line(t_list *list);
t_list	*find_last_node(t_list *list);
void	append_list(t_list **list, char *buf);
int		found_newline(t_list *list);
void	create_list(t_list **list, int fd);
void	dealloc(t_list **list, t_list *cleaned_node, char *buf);
void	polish_list(t_list **list);

#endif