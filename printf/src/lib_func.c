/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:12:24 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:12:25 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isdigit2(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_strncmp2(const char *s1, const char *s2, int n)
{
	int i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || i == n - 1)
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

int		ft_strlen2(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy2(char *dst, const char *src)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen2(src);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr2(const char *s, int c)
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
