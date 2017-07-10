/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:20:58 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/03 17:18:54 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	dst1 = (char*)dst;
	src1 = (char*)src;
	i = 0;
	while (i < n)
	{
		dst1[i] = (unsigned char)src1[i];
		if ((unsigned char)src1[i] == (unsigned char)c)
			return ((void*)(dst1 + i + 1));
		i++;
	}
	return (NULL);
}
