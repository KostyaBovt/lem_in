/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:01:06 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/02 14:39:10 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char*)malloc(size);
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	return ((void*)new);
}
