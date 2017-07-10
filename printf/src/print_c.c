/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:22:37 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:25:30 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_c(va_list ap, t_specif *now_basket, int *i)
{
	if (!ft_strncmp2(now_basket->len, "l", 2) || now_basket->type == 'C')
		return (print_c_wide(va_arg(ap, unsigned int), now_basket, i));
	return (print_c_short((unsigned char)va_arg(ap, int), now_basket, i));
}

int		print_c_wide(wchar_t c, t_specif *now_basket, int *i)
{
	char	filler;

	filler = (now_basket->zero) ? '0' : ' ';
	if (now_basket->minus)
	{
		write(1, &c, 4);
		put_n_char(' ', now_basket->width - 1);
	}
	else
	{
		put_n_char(filler, now_basket->width - 1);
		write(1, &c, 4);
	}
	*i += now_basket->skip;
	return (now_basket->width <= 1 ? 1 : now_basket->width);
}

int		print_c_short(unsigned char c, t_specif *now_basket, int *i)
{
	char	filler;

	filler = (now_basket->zero) ? '0' : ' ';
	if (now_basket->minus)
	{
		write(1, &c, 1);
		put_n_char(' ', now_basket->width - 1);
	}
	else
	{
		put_n_char(filler, now_basket->width - 1);
		write(1, &c, 1);
	}
	*i += now_basket->skip;
	return (now_basket->width <= 1 ? 1 : now_basket->width);
}

int		put_n_char(char c, int n)
{
	int		i;
	char	*to_print;

	if (n <= 0)
		return (0);
	to_print = (char*)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		to_print[i] = c;
		i++;
	}
	to_print[i] = '\0';
	write(1, to_print, n);
	free(to_print);
	return (n);
}
