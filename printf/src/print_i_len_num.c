/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_len_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:23:38 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 19:24:30 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			num_len(long long int num, int base)
{
	int count;

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

long long	num_delim(long long num, int base)
{
	long long delim;

	delim = 1;
	while (num / base)
	{
		delim *= base;
		num /= base;
	}
	return (delim);
}

long long	mod(long long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int			print_num(long long int num, int base, t_specif *now_basket)
{
	long long	delim;
	char		c;
	int			count;

	if (num == 0)
		return (print_null(now_basket) ? write(1, "0", 1) : 0);
	count = 0;
	delim = num_delim(num, base);
	while (delim)
	{
		c = mod((num / delim) % base) + '0';
		write(1, &c, 1);
		delim /= base;
		count++;
	}
	return (count);
}
