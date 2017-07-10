/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_len_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:58:17 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 19:25:35 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		num_len_u(t_ull num, int base)
{
	int		count;

	if (num == 0)
		return (1);
	count = 0;
	while (num)
	{
		count++;
		num /= base;
	}
	return (count);
}

t_ull	num_delim_u(t_ull num, int base)
{
	t_ull		delim;

	delim = 1;
	while (num / base)
	{
		delim *= base;
		num /= base;
	}
	return (delim);
}

int		print_null(t_specif *now_basket)
{
	if (now_basket->precis == 0 && now_basket->hash \
		&& (now_basket->type == 'o' || now_basket->type == 'O'))
		return (1);
	if (now_basket->precis == 0)
		return (0);
	return (1);
}

int		print_num_u(t_ull num, int base, t_specif *now_basket)
{
	t_ull	delim;
	char	c;
	int		count;
	int		f;
	char	cx;

	if (num == 0)
		return (print_null(now_basket) ? write(1, "0", 1) : 0);
	cx = (now_basket->type == 'X') ? 'A' : 'a';
	count = 0;
	delim = num_delim_u(num, base);
	while (delim)
	{
		f = (num / delim) % base > 9 ? 1 : 0;
		c = ((num / delim) % base) + (f ? (-10 + (int)cx) : '0');
		write(1, &c, 1);
		delim /= base;
		count++;
	}
	return (count);
}
