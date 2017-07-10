/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:55:01 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:55:02 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_fd_holder	*holder;
	t_fd_holder			*curr_holder;
	char				*temp_str;
	int					read_return;

	if ((curr_holder = get_curr_holder(fd, holder)) == NULL)
	{
		if ((read_return = read_until_endline(fd, &temp_str)) < 1)
			return (read_return);
		curr_holder = make_holder(fd);
		push_back_holder(curr_holder, &holder);
		append_holder_buff(fd, holder, temp_str);
		free(temp_str);
	}
	else
	{
		if (ft_strchr(curr_holder->buff, '\n') == NULL)
			if ((read_return = read_until_endline(fd, &temp_str)) > 0)
			{
				append_holder_buff(fd, holder, temp_str);
				free(temp_str);
			}
	}
	return (return_line(fd, holder, line));
}

int		read_until_endline(int fd, char **str)
{
	char		*buff;
	char		*temp;
	int			read_return;
	int			was_read;

	temp = NULL;
	was_read = 0;
	buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((read_return = read(fd, buff, BUFF_SIZE)) && read_return != -1)
	{
		was_read = 1;
		buff[read_return] = '\0';
		join_and_free(&temp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (was_read == 0)
	{
		free(buff);
		return (read_return == -1 ? -1 : 0);
	}
	*str = ft_strdup(temp);
	free(temp);
	free(buff);
	return (1);
}

void	join_and_free(char **dst, char *src)
{
	char *temp;

	if (!(*dst))
		*dst = ft_strdup(src);
	else
	{
		temp = ft_strjoin(*dst, src);
		free(*dst);
		*dst = temp;
	}
}

int		return_line(int fd, t_fd_holder *holder, char **ret_str)
{
	t_fd_holder	*curr_holder;
	int			line_size;

	curr_holder = get_curr_holder(fd, holder);
	if ((curr_holder->buff)[0] == '\0')
		return (0);
	line_size = get_line_size(curr_holder->buff);
	*ret_str = (char*)malloc(sizeof(char) * (line_size + 1));
	(*ret_str)[line_size] = '\0';
	ft_strncpy(*ret_str, curr_holder->buff, line_size);
	update_holder(curr_holder, line_size);
	return (1);
}

int		get_line_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
