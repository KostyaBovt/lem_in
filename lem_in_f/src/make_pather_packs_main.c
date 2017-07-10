/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pather_packs_main.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:04:44 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:04:45 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_pather_packs(t_pather *pather, t_pather_pack **pather_packs)
{
	t_pather_ptrs	*start_pather_ptrs;

	start_pather_ptrs = NULL;
	pather_packs_recurs(pather, 0, pather_packs, start_pather_ptrs);
}

void	pather_packs_recurs(t_pather *pather, t_pather *curr_pather, \
							t_pather_pack **pather_packs, \
							t_pather_ptrs *prv_pather_ptrs)
{
	t_pather_ptrs	*n_pth_ptrs;
	t_pather		*temp_pather;
	int				count;

	make_apnd_pth_ptrs(prv_pather_ptrs, curr_pather, &n_pth_ptrs);
	if (curr_pather && curr_pather->next == NULL)
		return (make_apnd_pth_pack(n_pth_ptrs, pather_packs));
	temp_pather = curr_pather ? curr_pather->next : pather;
	while (temp_pather && path_single(temp_pather))
	{
		make_apnd_pth_ptrs2(temp_pather, &n_pth_ptrs);
		temp_pather = temp_pather->next;
	}
	if (temp_pather == NULL)
		return (make_apnd_pth_pack(n_pth_ptrs, pather_packs));
	count = 0;
	while (temp_pather)
	{
		if (pather_compatible(temp_pather, n_pth_ptrs) && ++count)
			pather_packs_recurs(pather, temp_pather, pather_packs, n_pth_ptrs);
		temp_pather = temp_pather->next;
	}
	if (!count)
		return (make_apnd_pth_pack(n_pth_ptrs, pather_packs));
	del_pth_ptrs(&n_pth_ptrs);
}

int		pather_compatible(t_pather *pather, t_pather_ptrs *pather_ptrs)
{
	while (pather_ptrs)
	{
		if (pathes_cross(pather->path, (pather_ptrs->pather)->path))
			return (0);
		pather_ptrs = pather_ptrs->next;
	}
	return (1);
}

int		pathes_cross(t_path *path1, t_path *path2)
{
	t_path	*temp;

	while (path1)
	{
		temp = path2;
		while (path2)
		{
			if (path1->room == path2->room && \
				!(((t_room*)(path1->room))->end) && \
				!(((t_room*)(path1->room))->start))
				return (1);
			path2 = path2->next;
		}
		path2 = temp;
		path1 = path1->next;
	}
	return (0);
}

int		path_single(t_pather *pather)
{
	t_path	*curr_path;

	curr_path = pather->path;
	while (curr_path)
	{
		if (!((t_room*)(curr_path->room))->start && \
			!((t_room*)(curr_path->room))->end)
			if (count_path_elems(((t_room*)(curr_path->room))->nbors) > 2)
				return (0);
		curr_path = curr_path->next;
	}
	return (1);
}
