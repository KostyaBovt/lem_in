/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:06:23 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:06:24 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	apnd_path(t_path *new_path, t_path **path)
{
	t_path	*temp;

	if (!(*path))
		*path = new_path;
	else
	{
		temp = *path;
		while ((*path)->next)
			*path = (*path)->next;
		(*path)->next = new_path;
		(*path) = temp;
	}
}

t_path	*make_path_elem(char *room_name, t_room *rooms)
{
	t_path	*new_elem;

	new_elem = (t_path*)malloc(sizeof(t_path));
	new_elem->next = NULL;
	new_elem->name = ft_strdup(room_name);
	new_elem->room = get_room_adrr(room_name, rooms);
	return (new_elem);
}

void	make_apnd_path(char *room_name, t_path **curr_path, t_room *rooms)
{
	t_path	*new_path;

	new_path = make_path_elem(room_name, rooms);
	apnd_path(new_path, curr_path);
}

t_room	*get_room_adrr(char *name, t_room *rooms)
{
	while (rooms)
	{
		if (!ft_strcmp(name, rooms->name))
			return (rooms);
		rooms = rooms->next;
	}
	return (0);
}

void	del_path(t_path **path)
{
	t_path	*temp;

	while (*path)
	{
		temp = (*path)->next;
		free((*path)->name);
		free(*path);
		*path = temp;
	}
	*path = NULL;
}
