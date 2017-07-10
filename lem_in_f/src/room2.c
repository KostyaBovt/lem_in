/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:08:08 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:08:09 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*get_room_name(char *room)
{
	int		i;
	char	*name;

	i = -1;
	while (room[++i] != ' ')
		;
	name = (char*)malloc(sizeof(char) * (i + 1));
	name[i] = '\0';
	ft_strncpy(name, room, i);
	return (name);
}

void	get_room_xy(char *room, int *x, int *y)
{
	char	*temp;

	temp = ft_strchr(room, ' ') + 1;
	*x = ft_atoi(temp);
	temp = ft_strchr(temp, ' ') + 1;
	*y = ft_atoi(temp);
}

void	print_room(t_room *room, int lems)
{
	ft_printf("room->name  : {%s}\n", room->name);
	ft_printf("room->x     : {%i}\n", room->x);
	ft_printf("room->y     : {%i}\n", room->y);
	ft_printf("room->start : {%i}\n", room->start);
	ft_printf("room->end   : {%i}\n", room->end);
	ft_printf("room->lem   : {%i}\n", room->lem);
	if (room->start || room->end)
	{
		ft_printf("room->lems  : ");
		if (room->lems)
			print_ints(room->lems, lems);
		ft_printf("\n");
		ft_printf("room->lems_i: {%i}\n", room->lems_i);
	}
	print_nbors(room->nbors);
	ft_printf("room->next  : {%p}\n", room->next);
}

void	print_rooms(t_room *rooms, int lems)
{
	int		count;

	count = 1;
	while (rooms)
	{
		ft_printf("_______ROOM_#%i__(%p)_\n", count++, rooms);
		print_room(rooms, lems);
		ft_printf("\n");
		rooms = rooms->next;
	}
}

void	print_nbors(t_path *path)
{
	ft_printf("room->nbors : ");
	while (path)
	{
		ft_printf("{%s | %p} ", path->name, path->room);
		path = path->next;
	}
	ft_printf("\n");
}
