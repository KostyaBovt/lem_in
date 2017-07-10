/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:54:09 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/02 13:31:36 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*s1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	s1 = (char*)s;
	while (n)
	{
		if ((unsigned char)*s1 == c1)
			return ((void*)s1);
		n--;
		s1++;
	}
	return (NULL);
}
