/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:02:10 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:02:11 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		clear_all(t_gnl_list **inpt, t_room **rooms, \
			t_pather **pather, t_pather_pack **pather_pack)
{
	if (*inpt)
		del_gnl_list(inpt);
	if (*rooms)
		del_rooms(rooms);
	if (*pather)
		del_pather(pather);
	if (*pather_pack)
		del_pather_pack(pather_pack);
	return (0);
}
