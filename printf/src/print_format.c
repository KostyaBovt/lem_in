/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:25:54 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:27:18 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_format(const char *format, va_list ap, t_specif *basket)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			count += print_one(ap, basket, &i);
			if (basket->next)
				basket = basket->next;
		}
		else
		{
			count += print_char(&format[i], &i);
		}
	}
	return (count);
}

int		print_char(const char *format, int *i)
{
	int				len;
	unsigned char	*format2;

	format2 = (unsigned char*)format;
	len = char_len(*format2);
	write(1, format2, len);
	*i = *i + len - 1;
	return (len);
}

int		char_len(unsigned char c)
{
	int		i;

	i = 0;
	while (get_n_bit(c, i))
		i++;
	return (i == 0 ? 1 : i);
}

int		get_n_bit(unsigned char c, int n)
{
	int		mult;

	mult = 1 << (7 - n);
	mult = mult & c;
	mult = mult >> (7 - n);
	return (mult);
}
