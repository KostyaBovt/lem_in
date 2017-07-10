/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather_ptrs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:07:53 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:07:54 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_apnd_pth_ptrs(t_pather_ptrs *prv_pather_ptrs, \
		t_pather *curr_pather, \
		t_pather_ptrs **new_pather_ptrs)
{
	t_pather_ptrs *new_pather_ptrs_elem;

	*new_pather_ptrs = copy_pth_ptr(prv_pather_ptrs);
	new_pather_ptrs_elem = make_new_pth_ptr(curr_pather);
	apnd_pth_ptr(new_pather_ptrs_elem, new_pather_ptrs);
}

void	make_apnd_pth_ptrs2(t_pather *temp_pather, \
		t_pather_ptrs **new_pather_ptrs)
{
	t_pather_ptrs *new_pather_ptrs_elem;

	new_pather_ptrs_elem = make_new_pth_ptr(temp_pather);
	apnd_pth_ptr(new_pather_ptrs_elem, new_pather_ptrs);
}
