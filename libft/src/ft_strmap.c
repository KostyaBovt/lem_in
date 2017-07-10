/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:58:30 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/02 21:47:23 by kbovt            ###   ########.fr       */
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

char			*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	if (!s || !f)
		return (NULL);
	i = 0;
	ret = (char*)malloc(sizeof(char) * (sln(s) + 1));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
