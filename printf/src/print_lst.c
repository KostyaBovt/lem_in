/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:36:15 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:37:46 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**print_lst specifier is %w uses two argiments : t_list **list,  INT list limit
**if LIST LIMIT is 0 : list until terminating NULL list is printed
**all flag are ignored
*/

int				print_lst(t_list2 *list, int limit, \
				t_specif *now_basket, int *i)
{
	int				in;
	int				count;
	unsigned char	*tmp;

	*i = *i + now_basket->skip;
	count = 0;
	if (!list)
		return (0);
	in = 0;
	while (list && (!limit ? 1 : in < limit))
	{
		tmp = (unsigned char*)malloc(sizeof(char) * (list->content_size + 1));
		ft_strncpy2(tmp, (unsigned char*)(list->content), list->content_size);
		tmp[list->content_size] = '\0';
		*i = *i - now_basket->skip;
		count += print_s_short(tmp, now_basket, i);
		count += write(1, "\n", 1);
		in++;
		list = list->next;
	}
	return (count);
}

unsigned char	*ft_strncpy2(unsigned char *dst, unsigned char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
