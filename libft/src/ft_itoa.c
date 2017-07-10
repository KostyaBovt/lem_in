/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:19:17 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/02 19:00:13 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	glen(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	int	gdel(int n)
{
	int	del;

	del = 1;
	while (n / 10)
	{
		n = n / 10;
		del = del * 10;
	}
	return (del);
}

static	int	mod(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		i;
	int		del;

	i = 0;
	len = glen(n);
	del = gdel(n);
	ret = (char*)malloc(sizeof(char) * (len + (n >= 0 ? 1 : 2)));
	if (!ret)
		return (NULL);
	if (n < 0)
		ret[i++] = '-';
	while (del)
	{
		ret[i] = (char)(mod((n / del) % 10) + (int)'0');
		del /= 10;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
