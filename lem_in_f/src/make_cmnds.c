/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmnds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:04:19 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:04:20 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_cmnds(t_cmnds **cmnds, t_path *path, \
		int path_num, t_pather_pack *pather_pack)
{
	while (path)
	{
		if (((t_room*)(path->room))->end)
			return ;
		if (((t_room*)(path->room))->start)
		{
			if ((pather_pack->lems)[path_num])
				make_apnd_cmnd(cmnds, ((t_room*)(path->room)), \
				(t_room*)((path->next)->room));
		}
		else
		{
			if (((t_room*)(path->room))->lem)
				make_apnd_cmnd(cmnds, ((t_room*)(path->room)), \
				(t_room*)((path->next)->room));
		}
		path = path->next;
	}
}

void	apply_cmnd_se(t_cmnds *cmnds, int path_num, t_pather_pack *pather_pack)
{
	if (((pather_pack->lems)[path_num])--)
	{
		ft_printf("L%i-%s ", \
		((cmnds->from)->lems)[(cmnds->from)->lems_i], \
		(cmnds->to)->name);
		((cmnds->to)->lems)[((cmnds->to)->lems_i)++] = \
		((cmnds->from)->lems)[(cmnds->from)->lems_i];
		((cmnds->from)->lems)[((cmnds->from)->lems_i)++] = 0;
	}
}

void	apply_cmnd(t_cmnds *cmnds, int path_num, t_pather_pack *pather_pack)
{
	if (!((cmnds->to)->end) && !((cmnds->from)->start))
	{
		ft_printf("L%i-%s ", (cmnds->from)->lem, (cmnds->to)->name);
		(cmnds->to)->lem = (cmnds->from)->lem;
		(cmnds->from)->lem = 0;
	}
	if ((cmnds->to)->end && !((cmnds->from)->start))
	{
		ft_printf("L%i-%s ", (cmnds->from)->lem, (cmnds->to)->name);
		((cmnds->to)->lems)[((cmnds->to)->lems_i)++] = (cmnds->from)->lem;
		(cmnds->from)->lem = 0;
	}
	if (!(cmnds->to)->end && (cmnds->from)->start)
	{
		if (((pather_pack->lems)[path_num])--)
		{
			ft_printf("L%i-%s ", \
			((cmnds->from)->lems)[(cmnds->from)->lems_i], (cmnds->to)->name);
			(cmnds->to)->lem = ((cmnds->from)->lems)[(cmnds->from)->lems_i];
			((cmnds->from)->lems)[((cmnds->from)->lems_i)++] = 0;
		}
	}
	if ((cmnds->to)->end && (cmnds->from)->start)
		apply_cmnd_se(cmnds, path_num, pather_pack);
}

void	apply_cmnds(t_cmnds *cmnds, int path_num, t_pather_pack *pather_pack)
{
	while (cmnds)
	{
		apply_cmnd(cmnds, path_num, pather_pack);
		cmnds = cmnds->next;
	}
}
