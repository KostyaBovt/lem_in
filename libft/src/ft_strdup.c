/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:01:27 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/22 19:01:42 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char		*ft_strcpy(char *dst, const char *src)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_strdup(const char *s1)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new == NULL)
		return (NULL);
	new = ft_strcpy(new, s1);
	return (new);
}
