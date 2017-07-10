/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:44:58 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/01 14:48:08 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*currlist;
	t_list	*nextlist;

	currlist = *alst;
	nextlist = currlist->next;
	while (currlist)
	{
		(*del)(currlist->content, currlist->content_size);
		free(currlist);
		currlist = NULL;
		if (nextlist)
		{
			currlist = nextlist;
			nextlist = currlist->next;
		}
	}
	*alst = NULL;
}
