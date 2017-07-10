/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:40:43 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/24 20:42:23 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c2;
	size_t			i;
	char			*b2;

	c2 = (unsigned char)c;
	b2 = (char*)b;
	i = 0;
	while (i < len)
	{
		b2[i] = c2;
		i++;
	}
	return ((void*)b2);
}
