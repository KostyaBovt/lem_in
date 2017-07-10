/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:19:35 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:21:56 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**for print bits %b : width works like bytes to print
**precision is bytes to print per line
**all ather flag are ignored
*/

int		print_bits(void *ptr, t_specif *now_basket, int *i)
{
	unsigned char	*char_ptr;
	int				in;
	int				len;
	int				per_line;
	int				count;

	char_ptr = (unsigned char*)ptr;
	len = now_basket->width;
	per_line = now_basket->precis;
	*i += now_basket->skip;
	if (per_line == 0 || len <= 0)
		return (0);
	count = 0;
	in = -1;
	while (++in < len)
	{
		if ((in % per_line) != 0)
			count += write(1, " ", 1);
		if (in && in % per_line == 0)
			count += write(1, "\n", 1);
		print_char_bits(char_ptr[in]);
	}
	count += write(1, "\n", 1);
	return ((count += len * 8));
}

void	print_char_bits(unsigned char c)
{
	unsigned char	mult;
	unsigned char	print;
	int				i;

	i = 7;
	while (i >= 0)
	{
		mult = 1 << i;
		print = c & mult;
		print = print >> i;
		print += 48;
		write(1, &print, 1);
		i--;
	}
}
