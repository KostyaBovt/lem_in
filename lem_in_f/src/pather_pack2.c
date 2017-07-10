/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather_pack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:07:39 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:07:39 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	del_pather_pack(t_pather_pack **pather_packs)
{
	t_pather_pack	*temp;

	while (*pather_packs)
	{
		temp = (*pather_packs)->next;
		if ((*pather_packs)->lems)
			free((*pather_packs)->lems);
		if ((*pather_packs)->pathers_nums)
			free((*pather_packs)->pathers_nums);
		if ((*pather_packs)->pathers_lens)
			free((*pather_packs)->pathers_lens);
		del_pth_ptrs(&((*pather_packs)->pathers_ptrs));
		free(*pather_packs);
		*pather_packs = temp;
	}
}

void	print_pather_packs(t_pather_pack *pather_packs)
{
	int		count;

	count = 1;
	while (pather_packs)
	{
		ft_printf("____pather_pack #%i______________________________\n", count);
		ft_printf("moves         : %i\n", pather_packs->moves);
		ft_printf("lems          : ");
		print_ints(pather_packs->lems, pather_packs->pathers_qty);
		ft_printf("\n");
		ft_printf("pathers_qty   : %i\n", pather_packs->pathers_qty);
		ft_printf("pathers_nums  : ");
		print_ints(pather_packs->pathers_nums, pather_packs->pathers_qty);
		ft_printf("\n");
		ft_printf("pathers_lens  : ");
		print_ints(pather_packs->pathers_lens, pather_packs->pathers_qty);
		ft_printf("\n");
		ft_printf("pathers_ptrs  : ");
		print_pathers_ptrs(pather_packs->pathers_ptrs);
		ft_printf("\n\n");
		count++;
		pather_packs = pather_packs->next;
	}
}

void	print_pathers_ptrs(t_pather_ptrs *pth_ptrs)
{
	while (pth_ptrs)
	{
		ft_printf("{pather #%i | %p} ", (pth_ptrs->pather)->num, \
		pth_ptrs->pather);
		pth_ptrs = pth_ptrs->next;
	}
}
