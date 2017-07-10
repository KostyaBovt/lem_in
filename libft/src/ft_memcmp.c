/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:57:09 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/02 13:57:22 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *st1;
	char *st2;

	st1 = (char*)s1;
	st2 = (char*)s2;
	while (n)
	{
		if ((unsigned char)*st1 != (unsigned char)*st2)
			return ((int)((unsigned char)(*st1) - (unsigned char)(*st2)));
		st1++;
		st2++;
		n--;
	}
	return (0);
}
