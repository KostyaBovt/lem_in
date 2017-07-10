/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:03:20 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:03:20 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_gnl(t_gnl_list *list)
{
	int		count;

	if (!list)
	{
		ft_printf("While print GNL : gnl_list is NULL\n");
		return ;
	}
	count = 1;
	while (list)
	{
		ft_printf("line #%i: {%s}\n", count, list->line);
		list = list->next;
	}
}

void	del_gnl_list(t_gnl_list **head)
{
	t_gnl_list	*buf;
	t_gnl_list	*elem;

	buf = *head;
	while (buf)
	{
		elem = buf;
		buf = buf->next;
		free(elem->line);
		free(elem);
	}
}

void	print_inpt(t_gnl_list *inpt)
{
	while (inpt)
	{
		ft_printf("%s\n", inpt->line);
		inpt = inpt->next;
	}
	ft_printf("\n");
}
