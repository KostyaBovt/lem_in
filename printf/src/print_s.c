/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:48:55 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:50:03 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_s(va_list ap, t_specif *now_basket, int *i)
{
	if (!ft_strncmp2(now_basket->len, "l", 2) || now_basket->type == 'S')
		return (print_s_wide(va_arg(ap, unsigned char*), now_basket, i));
	return (print_s_short((unsigned char*)va_arg(ap, \
			unsigned char*), now_basket, i));
}
