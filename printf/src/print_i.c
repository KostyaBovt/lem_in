/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:27:39 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:27:45 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_i(va_list ap, t_specif *now_basket, int *i)
{
	if (!(*(now_basket->len)) && now_basket->type != 'D')
		return (print_i_len(va_arg(ap, int), now_basket, i));
	if (!ft_strncmp2(now_basket->len, "l", 2) || now_basket->type == 'D')
		return (print_i_len(va_arg(ap, long int), now_basket, i));
	if (!ft_strncmp2(now_basket->len, "ll", 2))
		return (print_i_len(va_arg(ap, long long int), now_basket, i));
	if (!ft_strncmp2(now_basket->len, "h", 2))
		return (print_i_len((short)va_arg(ap, int), now_basket, i));
	if (!ft_strncmp2(now_basket->len, "hh", 2))
		return (print_i_len((char)va_arg(ap, int), now_basket, i));
	if (!ft_strncmp2(now_basket->len, "z", 2))
		return (print_i_len(va_arg(ap, ssize_t), now_basket, i));
	if (!ft_strncmp2(now_basket->len, "j", 2))
		return (print_i_len(va_arg(ap, intmax_t), now_basket, i));
	return (0);
}
