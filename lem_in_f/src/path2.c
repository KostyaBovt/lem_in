/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:06:33 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:06:34 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*copy_path(t_path *path, t_room *rooms)
{
	t_path	*new_path;
	t_path	*new_path_elem;

	new_path = NULL;
	while (path)
	{
		new_path_elem = make_path_elem(path->name, rooms);
		apnd_path(new_path_elem, &new_path);
		path = path->next;
	}
	return (new_path);
}

int		count_path_elems(t_path *path)
{
	int		count;

	count = 0;
	while (path)
	{
		count++;
		path = path->next;
	}
	return (count);
}

void	print_path(t_path *path)
{
	ft_printf("path : ");
	while (path)
	{
		ft_printf("{%s | %p} ", path->name, path->room);
		path = path->next;
	}
	ft_printf("\n");
}
