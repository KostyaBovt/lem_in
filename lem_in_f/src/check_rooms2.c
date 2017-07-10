/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:01:58 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:01:59 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_l_rooms(t_room *rooms)
{
	while (rooms)
	{
		if ((rooms->name)[0] == 'L')
			return (prnt_err("room name can not start with \"L\""));
		rooms = rooms->next;
	}
	return (1);
}

int		check_big_rooms(t_room *rooms)
{
	int		start;
	int		end;

	end = 0;
	start = 0;
	while (rooms)
	{
		start += rooms->start;
		end += rooms->end;
		rooms = rooms->next;
	}
	if (start > 1 && end > 1)
		return (prnt_err("to many ##start and ##end commands"));
	if (start > 1)
		return (prnt_err("to many ##start commands"));
	if (end > 1)
		return (prnt_err("to many ##end commands"));
	if (!start && !end)
		return (prnt_err("no ##start and ##end commands"));
	if (!start)
		return (prnt_err("no ##start command"));
	if (!end)
		return (prnt_err("no ##end command"));
	return (1);
}

int		check_w_rooms(t_room *rooms)
{
	t_room	*temp_rooms;
	t_room	*head_rooms;
	char	*curr_name;
	int		count;

	head_rooms = rooms;
	temp_rooms = rooms;
	while (temp_rooms)
	{
		curr_name = ft_strdup(temp_rooms->name);
		rooms = head_rooms;
		count = 0;
		while (rooms)
		{
			if (!ft_strcmp(curr_name, rooms->name))
				count++;
			rooms = rooms->next;
		}
		free(curr_name);
		if (count > 1)
			return (prnt_err("room dublicates entered"));
		temp_rooms = temp_rooms->next;
	}
	return (1);
}

int		check_w_links(t_room *rooms)
{
	while (rooms)
	{
		if (!check_w_links_one(rooms->nbors))
			return (0);
		rooms = rooms->next;
	}
	return (1);
}

int		check_w_links_one(t_path *nbors)
{
	t_path	*head_nbors;
	t_path	*temp_nbors;
	int		count;
	char	*curr_name;

	head_nbors = nbors;
	temp_nbors = nbors;
	while (temp_nbors)
	{
		count = 0;
		curr_name = ft_strdup(temp_nbors->name);
		nbors = head_nbors;
		while (nbors)
		{
			if (!ft_strcmp(curr_name, nbors->name))
				count++;
			nbors = nbors->next;
		}
		free(curr_name);
		if (count > 1)
			return (prnt_err("links dublicates entered"));
		temp_nbors = temp_nbors->next;
	}
	return (1);
}
