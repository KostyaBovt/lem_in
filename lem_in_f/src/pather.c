/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pather.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:07:23 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:07:24 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		make_apnd_pather(t_path *new_path, t_pather **pather)
{
	t_pather	*new_pather;

	new_pather = make_new_pather(new_path);
	apnd_pather(new_pather, pather);
}

t_pather	*make_new_pather(t_path *new_path)
{
	t_pather	*new_pather;

	new_pather = (t_pather*)malloc(sizeof(t_pather));
	new_pather->path = new_path;
	new_pather->num = 0;
	new_pather->qty = count_path_elems(new_path);
	new_pather->next = NULL;
	return (new_pather);
}

void		apnd_pather(t_pather *new_pather, t_pather **pather)
{
	t_pather	*temp_pather;

	if (*pather == NULL)
	{
		new_pather->num = 1;
		*pather = new_pather;
		return ;
	}
	temp_pather = *pather;
	while ((*pather)->next)
		*pather = (*pather)->next;
	new_pather->num = (*pather)->num + 1;
	(*pather)->next = new_pather;
	(*pather) = temp_pather;
}

void		print_pather(t_pather *pather)
{
	int		count;

	count = 1;
	while (pather)
	{
		ft_printf("____pather #%i__(%p)____________________________\n", \
		count, pather);
		ft_printf("num  : %i\n", pather->num);
		ft_printf("len  : %i\n", pather->qty);
		print_path(pather->path);
		ft_printf("\n");
		count++;
		pather = pather->next;
	}
}

void		del_pather(t_pather **pather)
{
	t_pather	*temp;

	while (*pather)
	{
		temp = (*pather)->next;
		del_path(&((*pather)->path));
		free(*pather);
		*pather = temp;
	}
}
