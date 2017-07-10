/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:48:13 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 17:55:00 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_uoxq_len(unsigned long long num, int b, t_specif *bskt, int *i)
{
	int		count;

	count = 0;
	count += put_n_char(' ', count_spac_bu(num, b, bskt));
	count += print_hash(num, b, bskt);
	count += put_n_char('0', count_zeros_u(num, b, bskt));
	count += print_num_u(num, b, bskt);
	count += put_n_char(' ', count_spac_au(num, b, bskt));
	*i += bskt->skip;
	return (count);
}

int		count_spac_bu(unsigned long long num, int base, t_specif *bskt)
{
	int		to_print;
	int		prec_len;

	prec_len = 0;
	if (bskt->zero || bskt->minus)
		return (0);
	to_print = num_len(num, base);
	if (bskt->precis == 0 && num == 0 \
		&& !(base == 8 && bskt->hash))
		to_print = 0;
	if (bskt->precis > to_print)
		if (++prec_len)
			to_print = bskt->precis;
	if ((bskt->hash || bskt->type == 'p') \
		&& !(prec_len && base == 8))
		to_print += (base == 8) ? 1 : 2;
	return (bskt->width > to_print ? (bskt->width - to_print) : 0);
}

int		print_hash(unsigned long long num, int base, t_specif *bskt)
{
	int		prec_len;

	if ((!bskt->hash || num == 0) && bskt->type != 'p')
		return (0);
	prec_len = (bskt->precis > num_len(num, base)) ? 1 : 0;
	if (base == 8 && !prec_len)
		return (write(1, "0", 1));
	if (bskt->type == 'x' || bskt->type == 'p')
		return (write(1, "0x", 2));
	if (bskt->type == 'X')
		return (write(1, "0X", 2));
	return (0);
}

int		count_zeros_u(long long int num, int base, t_specif *bskt)
{
	int to_print;

	to_print = 0;
	if (bskt->zero)
	{
		to_print = num_len(num, base);
		if (bskt->hash || bskt->type == 'p')
			to_print += base == 8 ? 1 : 2;
		return (bskt->width > to_print ? \
				(bskt->width - to_print) : 0);
	}
	to_print = num_len(num, base);
	if (bskt->precis > to_print)
		return (bskt->precis - to_print);
	return (0);
}

int		count_spac_au(unsigned long long num, int base, t_specif *bskt)
{
	int		to_print;
	int		prec_len;

	prec_len = 0;
	if (bskt->zero || !(bskt->minus))
		return (0);
	to_print = num_len(num, base);
	if (bskt->precis == 0 && num == 0 \
		&& !(base == 8 && bskt->hash))
		to_print = 0;
	if (bskt->precis > to_print)
		if (++prec_len)
			to_print = bskt->precis;
	if ((bskt->hash || bskt->type == 'p') \
		&& !(prec_len && base == 8))
		to_print += (base == 8) ? 1 : 2;
	return (bskt->width > to_print ? (bskt->width - to_print) : 0);
}
