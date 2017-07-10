/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather_ptrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:07:47 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:07:48 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_pather_ptrs	*make_new_pth_ptr(t_pather *curr_pather)
{
	t_pather_ptrs	*new_pth_ptr;

	if (!curr_pather)
		return (0);
	new_pth_ptr = (t_pather_ptrs*)malloc(sizeof(t_pather_ptrs));
	new_pth_ptr->pather = curr_pather;
	new_pth_ptr->next = NULL;
	return (new_pth_ptr);
}

void			del_pth_ptrs(t_pather_ptrs **pth_ptrs)
{
	t_pather_ptrs	*temp;

	while (*pth_ptrs)
	{
		temp = (*pth_ptrs)->next;
		free(*pth_ptrs);
		*pth_ptrs = temp;
	}
	*pth_ptrs = NULL;
}

t_pather_ptrs	*copy_pth_ptr(t_pather_ptrs *pth_ptrs)
{
	t_pather_ptrs	*new_pth_ptrs_elem;
	t_pather_ptrs	*new_pth_ptrs;

	new_pth_ptrs = NULL;
	if (!pth_ptrs)
		return (0);
	while (pth_ptrs)
	{
		new_pth_ptrs_elem = make_new_pth_ptr(pth_ptrs->pather);
		apnd_pth_ptr(new_pth_ptrs_elem, &new_pth_ptrs);
		pth_ptrs = pth_ptrs->next;
	}
	return (new_pth_ptrs);
}

void			apnd_pth_ptr(t_pather_ptrs *pather_ptrs_elem,\
				t_pather_ptrs **pather_ptrs)
{
	t_pather_ptrs	*temp;

	if (*pather_ptrs == NULL)
		*pather_ptrs = pather_ptrs_elem;
	else
	{
		temp = *pather_ptrs;
		while ((*pather_ptrs)->next)
			*pather_ptrs = (*pather_ptrs)->next;
		(*pather_ptrs)->next = pather_ptrs_elem;
		*pather_ptrs = temp;
	}
}

void			print_pth_ptrs(t_pather_ptrs *pth_ptrs)
{
	while (pth_ptrs)
	{
		ft_printf("pather #%i (%p) | ", (pth_ptrs->pather)->num, \
		pth_ptrs->pather);
		pth_ptrs = pth_ptrs->next;
	}
	ft_printf("\n");
}
