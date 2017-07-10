/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:01:52 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:01:53 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_rooms(t_room *rooms)
{
	if (!rooms)
		return (prnt_err("no rooms entered at all"));
	if (!check_big_rooms(rooms))
		return (0);
	if (!check_w_rooms(rooms))
		return (0);
	if (!check_w_links(rooms))
		return (0);
	if (!check_l_rooms(rooms))
		return (0);
	return (1);
}
