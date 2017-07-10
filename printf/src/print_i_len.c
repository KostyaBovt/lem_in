/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:28:21 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:35:42 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_i_len(long long int num, t_specif *now_basket, int *i)
{
	int		count;

	count = 0;
	count += put_n_char(' ', count_spac_b(num, now_basket));
	count += print_sign(num, now_basket);
	count += put_n_char('0', count_zeros(num, now_basket));
	count += print_num(num, 10, now_basket);
	count += put_n_char(' ', count_spac_a(num, now_basket));
	*i += now_basket->skip;
	return (count);
}

int		count_spac_b(long long int num, t_specif *now_basket)
{
	int		to_print;

	if (now_basket->zero || now_basket->minus)
		return (0);
	to_print = num_len(num, 10);
	if (now_basket->precis == 0 && num == 0)
		to_print = 0;
	if (now_basket->precis > to_print)
		to_print = now_basket->precis;
	if (now_basket->plus || now_basket->space || num < 0)
		to_print++;
	return (now_basket->width > to_print ? (now_basket->width - to_print) : 0);
}

int		print_sign(long long int num, t_specif *now_basket)
{
	if (num >= 0 && !(now_basket->plus) && !(now_basket->space))
		return (0);
	if (now_basket->plus && num >= 0)
		write(1, "+", 1);
	if (now_basket->space && num >= 0)
		write(1, " ", 1);
	if (num < 0)
		write(1, "-", 1);
	return (1);
}

int		count_zeros(long long int num, t_specif *now_basket)
{
	int	to_print;

	to_print = 0;
	if (now_basket->zero)
	{
		to_print = num_len(num, 10);
		to_print += (num < 0 || now_basket->plus || now_basket->space) ? 1 : 0;
		return (now_basket->width > to_print ? \
				(now_basket->width - to_print) : 0);
	}
	to_print = num_len(num, 10);
	if (now_basket->precis > to_print)
		return (now_basket->precis - to_print);
	return (0);
}

int		count_spac_a(long long int num, t_specif *now_basket)
{
	int		to_print;

	if (now_basket->zero || !(now_basket->minus))
		return (0);
	to_print = num_len(num, 10);
	if (now_basket->precis == 0 && num == 0)
		to_print = 0;
	if (now_basket->precis > to_print)
		to_print = now_basket->precis;
	if (now_basket->plus || now_basket->space || num < 0)
		to_print++;
	return (now_basket->width > to_print ? (now_basket->width - to_print) : 0);
}
