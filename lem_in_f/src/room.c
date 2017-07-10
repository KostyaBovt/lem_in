/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:08:01 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:08:02 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*make_new_room(int type, char *name, int cx, int cy)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(name);
	room->x = cx;
	room->y = cy;
	room->start = (type == 2) ? 1 : 0;
	room->end = (type == 3) ? 1 : 0;
	room->lem = 0;
	room->lems = NULL;
	room->lems_i = 0;
	room->nbors = NULL;
	room->next = NULL;
	return (room);
}

void	del_rooms(t_room **rooms)
{
	t_room	*temp;

	while (*rooms)
	{
		temp = (*rooms)->next;
		if ((*rooms)->name)
			free((*rooms)->name);
		if ((*rooms)->lems)
			free((*rooms)->lems);
		del_path(&((*rooms)->nbors));
		free(*rooms);
		*rooms = temp;
	}
	*rooms = NULL;
}

void	apnd_room(t_room *new_room, t_room **rooms)
{
	t_room	*temp;

	if (!(*rooms))
		*rooms = new_room;
	else
	{
		temp = *rooms;
		while ((*rooms)->next)
			*rooms = (*rooms)->next;
		(*rooms)->next = new_room;
		*rooms = temp;
	}
}

void	add_room_front(t_room *new_room, t_room **rooms)
{
	new_room->next = *rooms;
	*rooms = new_room;
}

void	add_room(int type, char *room, t_room **rooms)
{
	t_room	*new_room;
	char	*name;
	int		x;
	int		y;

	name = get_room_name(room);
	get_room_xy(room, &x, &y);
	new_room = make_new_room(type, name, x, y);
	free(name);
	if (type == 4 || type == 3)
		apnd_room(new_room, rooms);
	else
		add_room_front(new_room, rooms);
}
