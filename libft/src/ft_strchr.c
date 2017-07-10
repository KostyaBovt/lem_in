/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:18:14 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/23 18:18:23 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	const char *ret;

	ret = s;
	while (*ret != (char)c && *ret)
		ret++;
	if (!((char)c) && !(*ret))
		return ((char*)ret);
	if ((char)c && !(*ret))
		return (NULL);
	return ((char*)ret);
}
