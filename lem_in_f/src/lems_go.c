/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lems_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:03:36 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:03:37 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_pather_pack	*min_moves(t_pather_pack *pather_packs)
{
	t_pather_pack	*min_pack;

	min_pack = pather_packs;
	while (pather_packs)
	{
		if (pather_packs->moves < min_pack->moves)
			min_pack = pather_packs;
		pather_packs = pather_packs->next;
	}
	return (min_pack);
}

void			lems_go(int lems, t_room *rooms, t_pather_pack *pather_pack)
{
	t_cmnds			*cmnds;
	t_room			*end_room;
	t_pather_ptrs	*pth_ptrs;
	int				path_num;

	init_lems(lems, rooms);
	cmnds = NULL;
	end_room = get_end_room(rooms);
	while (!lems_home(end_room, lems))
	{
		pth_ptrs = pather_pack->pathers_ptrs;
		path_num = 0;
		while (pth_ptrs)
		{
			make_cmnds(&cmnds, (pth_ptrs->pather)->path, path_num, pather_pack);
			apply_cmnds(cmnds, path_num, pather_pack);
			del_cmnds(&cmnds);
			path_num++;
			pth_ptrs = pth_ptrs->next;
		}
		ft_printf("\n");
	}
}

void			init_lems(int lems, t_room *rooms)
{
	int		i;

	while (rooms)
	{
		if (rooms->start)
		{
			rooms->lems = (int*)malloc(sizeof(int) * lems);
			i = -1;
			while (++i < lems)
				(rooms->lems)[i] = i + 1;
		}
		if (rooms->end)
		{
			rooms->lems = (int*)malloc(sizeof(int) * lems);
			ft_memset((void*)rooms->lems, 0, (sizeof(int)) * lems);
		}
		rooms = rooms->next;
	}
}

int				lems_home(t_room *room, int lems)
{
	if (room->lems_i == lems)
		return (1);
	return (0);
}

t_room			*get_end_room(t_room *rooms)
{
	while (rooms)
	{
		if (rooms->end)
			return (rooms);
		rooms = rooms->next;
	}
	return (0);
}
