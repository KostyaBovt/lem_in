/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather_pack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:07:33 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:07:34 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			make_apnd_pth_pack(t_pather_ptrs *pather_ptrs, \
				t_pather_pack **pather_packs)
{
	t_pather_pack	*new_pather_pack;

	new_pather_pack = make_pather_pack(pather_ptrs);
	apnd_pather_pack(new_pather_pack, pather_packs);
}

t_pather_pack	*make_pather_pack(t_pather_ptrs *pather_ptrs)
{
	t_pather_pack	*new_pather_pack;

	new_pather_pack = (t_pather_pack*)malloc(sizeof(t_pather_pack));
	new_pather_pack->moves = 0;
	new_pather_pack->lems = NULL;
	new_pather_pack->pathers_qty = 0;
	new_pather_pack->pathers_nums = NULL;
	new_pather_pack->pathers_lens = NULL;
	fill_pather_pack(new_pather_pack, pather_ptrs);
	new_pather_pack->pathers_ptrs = pather_ptrs;
	new_pather_pack->next = NULL;
	return (new_pather_pack);
}

void			apnd_pather_pack(t_pather_pack *new_pather_pack, \
				t_pather_pack **pather_packs)
{
	t_pather_pack	*temp;

	if (*pather_packs == NULL)
		*pather_packs = new_pather_pack;
	else
	{
		temp = *pather_packs;
		while ((*pather_packs)->next)
			*pather_packs = (*pather_packs)->next;
		(*pather_packs)->next = new_pather_pack;
		*pather_packs = temp;
	}
}

void			fill_pather_pack(t_pather_pack *pather_pack, \
				t_pather_ptrs *pather_ptrs)
{
	t_pather_ptrs	*temp;
	int				count;
	int				i;

	count = 0;
	temp = pather_ptrs;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	pather_pack->pathers_qty = count;
	pather_pack->lems = (int*)malloc(sizeof(int) * count);
	pather_pack->pathers_nums = (int*)malloc(sizeof(int) * count);
	pather_pack->pathers_lens = (int*)malloc(sizeof(int) * count);
	i = 0;
	while (pather_ptrs)
	{
		(pather_pack->lems)[i] = 0;
		(pather_pack->pathers_nums)[i] = (pather_ptrs->pather)->num;
		(pather_pack->pathers_lens)[i] = (pather_ptrs->pather)->qty - 1;
		pather_ptrs = pather_ptrs->next;
		i++;
	}
}
