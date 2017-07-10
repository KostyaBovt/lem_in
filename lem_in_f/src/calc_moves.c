/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:00:49 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:00:55 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	calc_moves(t_pather_pack *pather_packs, int lems)
{
	while (pather_packs)
	{
		calc_lems(pather_packs, lems);
		calc_moves_one(pather_packs);
		pather_packs = pather_packs->next;
	}
}

void	calc_lems(t_pather_pack *pather_packs, int lems)
{
	int		x;
	int		i;
	int		min;
	int		diffs[pather_packs->pathers_qty];

	min = get_min_ints(pather_packs->pathers_lens, pather_packs->pathers_qty);
	i = -1;
	while (++i < pather_packs->pathers_qty)
		diffs[i] = (pather_packs->pathers_lens)[i] - min;
	if (lems_less_diffs(diffs, pather_packs->pathers_qty, lems))
		return (calc_lems_small(diffs, pather_packs, lems));
	x = (lems + ints_sum(diffs, pather_packs->pathers_qty)) \
	/ pather_packs->pathers_qty;
	i = -1;
	while (++i < pather_packs->pathers_qty)
		(pather_packs->lems)[i] = x - diffs[i];
	x = lems - ints_sum(pather_packs->lems, pather_packs->pathers_qty);
	i = 0;
	while (x--)
	{
		(pather_packs->lems)[i] += 1;
		i++;
	}
}

void	calc_moves_one(t_pather_pack *pather_packs)
{
	int		moves[pather_packs->pathers_qty];
	int		i;

	i = -1;
	while (++i < pather_packs->pathers_qty)
	{
		if ((pather_packs->lems)[i] == 0)
		{
			moves[i] = 0;
			continue ;
		}
		moves[i] = (pather_packs->lems)[i] + \
		(pather_packs->pathers_lens)[i] - 1;
	}
	pather_packs->moves = get_max_ints(moves, pather_packs->pathers_qty);
}

int		lems_less_diffs(int *diffs, int qty, int lems)
{
	int		r_diffs_sum;
	int		i;
	int		diff_max;

	diff_max = get_max_ints(diffs, qty);
	r_diffs_sum = 0;
	i = -1;
	while (++i < qty)
		r_diffs_sum += diff_max - diffs[i];
	if (lems < r_diffs_sum)
		return (1);
	return (0);
}

void	calc_lems_small(int *diffs, t_pather_pack *pather_packs, int lems)
{
	int		i;
	int		to_reduce;
	int		to_minus;
	int		r_diffs[pather_packs->pathers_qty];

	get_r_diffs(r_diffs, diffs, pather_packs->pathers_qty);
	to_reduce = ints_sum(r_diffs, pather_packs->pathers_qty) - lems;
	while (to_reduce)
	{
		if (to_reduce < count_not_zero_ints(r_diffs, pather_packs->pathers_qty))
			return (calc_lems_small_rest(r_diffs, to_reduce, pather_packs));
		to_minus = to_reduce / \
		count_not_zero_ints(r_diffs, pather_packs->pathers_qty);
		i = -1;
		while (++i < pather_packs->pathers_qty)
			r_diffs[i] = r_diffs[i] < to_minus ? 0 : r_diffs[i] - to_minus;
		to_reduce = ints_sum(r_diffs, pather_packs->pathers_qty) - lems;
	}
	i = -1;
	while (++i < pather_packs->pathers_qty)
		(pather_packs->lems)[i] = r_diffs[i];
}
