/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:03:46 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:03:47 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_rooms_exist(char *link, t_room *rooms)
{
	char	*room1;
	char	*room2;

	get_linked_rooms(link, &room1, &room2);
	if (!is_room_exist(room1, rooms) || \
		!is_room_exist(room2, rooms))
	{
		free(room1);
		free(room2);
		return (0);
	}
	free(room1);
	free(room2);
	return (1);
}

void	get_linked_rooms(char *link, char **room1, char **room2)
{
	int		i;

	i = -1;
	while (link[++i] != '-')
		;
	*room1 = (char*)malloc(sizeof(char) * (i + 1));
	(*room1)[i] = '\0';
	ft_strncpy(*room1, link, i);
	*room2 = ft_strdup(link + i + 1);
}

int		is_room_exist(char *room, t_room *rooms)
{
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, room))
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

int		add_link(char *link, t_room *rooms)
{
	char	*room1;
	char	*room2;

	get_linked_rooms(link, &room1, &room2);
	if (!ft_strcmp(room1, room2))
		return (prnt_err("you cann`t input link between one room"));
	add_nbor(room1, room2, rooms);
	add_nbor(room2, room1, rooms);
	free(room1);
	free(room2);
	return (1);
}

void	add_nbor(char *room1, char *room2, t_room *rooms)
{
	t_room	*head_rooms;

	head_rooms = rooms;
	while (rooms)
	{
		if (!ft_strcmp(room1, rooms->name))
		{
			make_apnd_path(room2, &(rooms->nbors), head_rooms);
			break ;
		}
		rooms = rooms->next;
	}
}
