/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:08:42 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/29 19:09:52 by kbovt            ###   ########.fr       */
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

static	void	putch_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	int	del;

	del = gdel(n);
	if (n < 0)
		putch_fd('-', fd);
	while (del)
	{
		putch_fd((char)(mod((n / del) % 10) + (int)'0'), fd);
		del /= 10;
	}
}
