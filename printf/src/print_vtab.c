/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:07:48 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 18:08:07 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**vtab specifier is %v uses two argiments : CHAR **TAB,  INT TABS LIMIT
**if TABS LIMIT is 0 : tabs until terminating NULL tabs is printed
**all flag works for tab strings as type s
*/

int		print_vtab(char **vtab, int tabs, t_specif *now_basket, int *i)
{
	int		in;
	int		count;

	*i = *i + now_basket->skip;
	count = 0;
	if (!vtab)
		return (0);
	in = -1;
	while (vtab[++in] && (!tabs ? 1 : in < tabs))
	{
		*i = *i - now_basket->skip;
		count += print_s_short((unsigned char*)vtab[in], now_basket, i);
		count += write(1, "\n", 1);
	}
	return (count);
}
