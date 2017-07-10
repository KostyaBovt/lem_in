/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:25:05 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/03 16:31:00 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new_list1;
	t_list	*new_list2;

	if (!lst)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		if (!ret)
		{
			new_list1 = (*f)(lst);
			ret = new_list1;
		}
		else
		{
			new_list2 = (*f)(lst);
			new_list1->next = new_list2;
			new_list1 = new_list2;
		}
		lst = lst->next;
	}
	return (ret);
}
