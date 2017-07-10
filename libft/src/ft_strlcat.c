/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:28:34 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/24 18:54:14 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	size_t	sln(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t tcp;
	size_t i;
	size_t j;
	size_t dstl;

	dstl = sln(dst);
	tcp = size > (sln(dst) + 1) ? size - sln(dst) - 1 : 0;
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (j < tcp && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return ((size_t)(sln(src) + ((size > dstl) ? dstl : size)));
}
