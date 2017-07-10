/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:04:00 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:04:01 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_room			*rooms;
	t_gnl_list		*inpt;
	int				lems;
	t_pather		*pather;
	t_pather_pack	*pather_packs;

	rooms = NULL;
	pather = NULL;
	pather_packs = NULL;
	inpt = get_inpt_fd(0);
	if (!check_inpt(inpt, &rooms, &lems))
		return (clear_all(&inpt, &rooms, &pather, &pather_packs));
	make_pather(rooms, &pather);
	if (!pather)
	{
		prnt_err("no way from start to end");
		return (clear_all(&inpt, &rooms, &pather, &pather_packs));
	}
	make_pather_packs(pather, &pather_packs);
	calc_moves(pather_packs, lems);
	print_inpt(inpt);
	lems_go(lems, rooms, min_moves(pather_packs));
	clear_all(&inpt, &rooms, &pather, &pather_packs);
	return (0);
}
