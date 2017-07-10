/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:52:19 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:52:21 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_fd_holder
{
	int					fd;
	char				*buff;
	struct s_fd_holder	*next;
}						t_fd_holder;

int						get_next_line(const int fd, char **line);
t_fd_holder				*make_holder(int fd);
int						read_until_endline(int fd, char **str);
void					append_holder_buff(int fd, t_fd_holder *holder, \
						char *str);
void					join_and_free(char **dst, char *src);
t_fd_holder				*get_curr_holder(int fd, t_fd_holder *holder);
void					push_back_holder(t_fd_holder *curr_holder, \
						t_fd_holder **holder);
int						return_line(int fd, t_fd_holder *holder, \
						char **ret_str);
int						get_line_size(char *str);
void					update_holder(t_fd_holder *curr_holder, \
						int line_size);

#endif
