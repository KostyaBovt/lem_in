/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:56:12 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:56:13 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_fd_holder	*make_holder(int fd)
{
	t_fd_holder	*new_holder;

	new_holder = (t_fd_holder*)malloc(sizeof(t_fd_holder));
	new_holder->fd = fd;
	new_holder->buff = NULL;
	new_holder->next = NULL;
	return (new_holder);
}

void		append_holder_buff(int fd, t_fd_holder *holder, char *str)
{
	t_fd_holder	*curr_holder;

	curr_holder = get_curr_holder(fd, holder);
	if (curr_holder->buff == NULL)
	{
		curr_holder->buff = ft_strdup(str);
		return ;
	}
	else
		join_and_free(&(curr_holder->buff), str);
}

t_fd_holder	*get_curr_holder(int fd, t_fd_holder *holder)
{
	t_fd_holder *temp;

	if (holder == NULL)
		return (NULL);
	temp = holder;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void		push_back_holder(t_fd_holder *curr_holder, t_fd_holder **holder)
{
	t_fd_holder	*temp;

	if (*holder == NULL)
	{
		*holder = curr_holder;
		return ;
	}
	temp = *holder;
	while ((*holder)->next)
		(*holder) = (*holder)->next;
	(*holder)->next = curr_holder;
	(*holder) = temp;
}

void		update_holder(t_fd_holder *curr_holder, int line_size)
{
	char	*temp;
	int		n_skipper;

	n_skipper = ((curr_holder->buff)[line_size] == '\n') ? 1 : 0;
	temp = ft_strdup((curr_holder->buff) + line_size + n_skipper);
	free(curr_holder->buff);
	curr_holder->buff = temp;
}
