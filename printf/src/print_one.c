/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:39:39 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:48:17 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_one(va_list ap, t_specif *now_bskt, int *i)
{
	if (ft_strlen2(now_bskt->aster))
		process_wildcard(ap, now_bskt);
	if (now_bskt->type == 'v')
		return (print_vtab(va_arg(ap, char**), va_arg(ap, int), now_bskt, i));
	if (now_bskt->type == 'w')
		return (print_lst(va_arg(ap, t_list2*), va_arg(ap, int), now_bskt, i));
	if (now_bskt->type == 'm')
		return (print_memory(va_arg(ap, void*), now_bskt, i));
	if (now_bskt->type == 'b')
		return (print_bits(va_arg(ap, void*), now_bskt, i));
	if (now_bskt->type == 'c' || now_bskt->type == 'C')
		return (print_c(ap, now_bskt, i));
	if (now_bskt->type == 's' || now_bskt->type == 'S')
		return (print_s(ap, now_bskt, i));
	if (now_bskt->type == 'i' || now_bskt->type == 'd' \
		|| now_bskt->type == 'D')
		return (print_i(ap, now_bskt, i));
	if (now_bskt->type == 'u' || now_bskt->type == 'U' \
		|| now_bskt->type == 'o' || now_bskt->type == 'O' \
		|| now_bskt->type == 'x' || now_bskt->type == 'X' \
		|| now_bskt->type == 'p' || now_bskt->type == 'q')
		return (print_uoxq(ap, now_bskt, i));
	if (now_bskt->type == 0)
		return (print_nothing(now_bskt, i));
	return (print_undef(now_bskt, i));
}

void	process_wildcard(va_list ap, t_specif *now_basket)
{
	int		aster_count;
	int		i;
	int		temp;

	aster_count = ft_strlen2(now_basket->aster);
	i = -1;
	while (++i < aster_count)
	{
		temp = va_arg(ap, int);
		if ((now_basket->aster)[i] == 'w')
		{
			if (temp < 0)
			{
				now_basket->minus = '-';
				now_basket->zero = 0;
			}
			if (now_basket->width == -1)
				now_basket->width = temp < 0 ? -temp : temp;
		}
		if ((now_basket->aster)[i] == 'p' && now_basket->precis == -1)
			now_basket->precis = temp < 0 ? -1 : temp;
	}
}

int		print_nothing(t_specif *now_basket, int *i)
{
	*i += now_basket->skip - 1;
	return (0);
}

int		print_undef(t_specif *now_basket, int *i)
{
	int		w;
	int		ret;
	char	filler;

	ret = 0;
	*i += now_basket->skip;
	if (now_basket->minus)
	{
		ret += write(1, &(now_basket->type), 1);
		w = (now_basket->width > 1) ? (now_basket->width - 1) : 0;
		ret += put_n_char(' ', w);
		return (ret);
	}
	filler = now_basket->zero ? '0' : ' ';
	w = (now_basket->width > 1) ? (now_basket->width - 1) : 0;
	ret += put_n_char(filler, w);
	ret += write(1, &(now_basket->type), 1);
	return (ret);
}
