/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pather.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:04:32 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:04:33 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_pather(t_room *rooms, t_pather **pather)
{
	t_path	*start_path;

	start_path = NULL;
	pather_recurs(pather, start_path, rooms, rooms);
}

void	pather_recurs(t_pather **pather, t_path *prv_stp_path, \
		t_room *curr_room, t_room *rooms)
{
	t_path	*new_path;
	t_path	*new_path_elem;
	t_path	*temp_path;

	if (exist_in_path(curr_room->name, prv_stp_path))
		return ;
	new_path = copy_path(prv_stp_path, rooms);
	new_path_elem = make_path_elem(curr_room->name, rooms);
	apnd_path(new_path_elem, &new_path);
	if (curr_room->end)
		return (make_apnd_pather(new_path, pather));
	temp_path = curr_room->nbors;
	while (temp_path)
	{
		pather_recurs(pather, new_path, (t_room*)(temp_path->room), rooms);
		temp_path = temp_path->next;
	}
	del_path(&new_path);
}

int		exist_in_path(char *name, t_path *path)
{
	t_path	*temp_path;

	temp_path = path;
	while (temp_path)
	{
		if (!ft_strcmp(name, temp_path->name))
			return (1);
		temp_path = temp_path->next;
	}
	return (0);
}
