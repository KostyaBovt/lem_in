/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:40:44 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/26 19:43:04 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dst1;
	char *src1;

	dst1 = (char*)dst;
	src1 = (char*)src;
	if (src1 > dst1)
		while (len--)
		{
			*dst1 = *src1;
			dst1++;
			src1++;
		}
	if (dst1 > src1)
		while (len)
		{
			*(dst1 + len - 1) = *(src1 + len - 1);
			len--;
		}
	return (dst);
}
