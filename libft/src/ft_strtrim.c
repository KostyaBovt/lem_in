/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:15:14 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/02 22:11:08 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	sln(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static	size_t	issp(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

static	char	*empt(void)
{
	char *ret;

	ret = (char*)malloc(sizeof(char) * 1);
	ret[0] = '\0';
	return (ret);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	while (issp(*s))
		s++;
	len = sln(s);
	if (!len)
		return (empt());
	while (issp(s[len - 1]))
		len--;
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (len)
	{
		ret[i] = s[i];
		len--;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
