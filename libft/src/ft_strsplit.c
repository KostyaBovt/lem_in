/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:43:01 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/02 22:08:52 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		wds(const char *s, char c)
{
	int n;

	n = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			n++;
		s++;
	}
	return (n);
}

static	char	*addelem(const char *s, int i, int j)
{
	char	*new;
	int		len;
	int		ni;

	len = i - j;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ni = 0;
	while (len)
	{
		new[ni] = s[j];
		ni++;
		j++;
		len--;
	}
	new[ni] = '\0';
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		n;

	if (!s)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (wds(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i - j)
			ret[n++] = addelem(s, i, j);
	}
	ret[n] = NULL;
	return (ret);
}
