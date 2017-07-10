/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:02:24 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:02:25 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	make_apnd_cmnd(t_cmnds **cmnds, t_room *from, t_room *to)
{
	t_cmnds	*new_cmnd;

	new_cmnd = make_one_cmnd(from, to);
	apnd_cmnd(new_cmnd, cmnds);
}

void	apnd_cmnd(t_cmnds *new_cmnd, t_cmnds **cmnds)
{
	if (*cmnds == NULL)
		*cmnds = new_cmnd;
	else
	{
		new_cmnd->next = *cmnds;
		*cmnds = new_cmnd;
	}
}

t_cmnds	*make_one_cmnd(t_room *from, t_room *to)
{
	t_cmnds	*new_cmnd;

	new_cmnd = (t_cmnds*)malloc(sizeof(t_cmnds));
	new_cmnd->from = from;
	new_cmnd->to = to;
	new_cmnd->next = NULL;
	return (new_cmnd);
}

void	del_cmnds(t_cmnds **cmnds)
{
	t_cmnds	*temp;

	if (*cmnds == NULL)
		return ;
	else
	{
		while (*cmnds)
		{
			temp = (*cmnds)->next;
			free(*cmnds);
			*cmnds = temp;
		}
	}
	*cmnds = NULL;
}
