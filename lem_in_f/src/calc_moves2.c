/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:01:11 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:01:12 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	get_r_diffs(int *r_diffs, int *diffs, int q_ty)
{
	int		max;
	int		i;

	max = get_max_ints(diffs, q_ty);
	i = -1;
	while (++i < q_ty)
		r_diffs[i] = max - diffs[i];
}

int		count_not_zero_ints(int *diffs, int q_ty)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < q_ty)
		if (diffs[i] > 0)
			count++;
	return (count);
}

void	calc_lems_small_rest(int *r_diffs, int to_reduce, \
		t_pather_pack *pather_packs)
{
	int		i;

	i = -1;
	while (++i < pather_packs->pathers_qty && to_reduce)
		if (r_diffs[i] > 0)
		{
			r_diffs[i] -= 1;
			to_reduce--;
		}
	i = -1;
	while (++i < pather_packs->pathers_qty)
		(pather_packs->lems)[i] = r_diffs[i];
}
