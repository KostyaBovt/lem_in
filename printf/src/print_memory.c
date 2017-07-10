/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:38:11 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:39:18 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**for prinе_memory %m: width works like bytes to print from the memory
**all other flags are ignored
*/

int		print_hex(unsigned char c)
{
	int		num;
	char	print;

	num = (int)c;
	print = (num / 16) % 16 + ((num / 16 % 16 > 9) ? (-10 + 'a') : '0');
	write(1, &print, 1);
	print = num % 16 + ((num % 16 > 9) ? (-10 + 'a') : '0');
	write(1, &print, 1);
	return (2);
}

int		print_dots(unsigned char **tmp, int flag, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if ((*tmp)[i] >= 32 && (*tmp)[i] <= 126)
			write(1, &((*tmp)[i]), 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
	if (flag)
		*tmp = *tmp + 16;
	return (len + 1);
}

int		print_memory_sub(unsigned char *addr, int size)
{
	unsigned char	*tmp;
	int				i;
	int				spaces;
	int				last;
	int				count;

	count = 0;
	tmp = addr;
	i = -1;
	while (++i < size)
	{
		if (i % 2 == 0 && i != 0)
			count += write(1, " ", 1);
		if (i % 16 == 0 && i != 0)
			count += print_dots(&tmp, 1, 16);
		count += print_hex(addr[i]);
	}
	last = size % 16;
	spaces = last * 2 + ((last % 2) ? (last / 2) : (last / 2) - 1);
	spaces = 40 - spaces;
	spaces = last == 0 ? 1 : spaces;
	while (spaces--)
		count += write(1, " ", 1);
	count += print_dots(&tmp, 0, last == 0 ? 16 : last);
	return (count);
}

int		print_memory(void *addr, t_specif *now_basket, int *i)
{
	*i += now_basket->skip;
	if (now_basket->width <= 0 || !addr)
		return (0);
	return (print_memory_sub((unsigned char*)addr, now_basket->width));
}
