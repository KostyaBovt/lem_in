/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:44:40 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/29 16:45:06 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	int		gdel(int n)
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

static	int		mod(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

static	void	putch(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	int		del;

	del = gdel(n);
	if (n < 0)
		putch('-');
	while (del)
	{
		putch((char)(mod((n / del) % 10) + (int)'0'));
		del /= 10;
	}
}
