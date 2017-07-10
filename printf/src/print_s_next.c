/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:50:38 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:52:41 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_s_wide(unsigned char *s_wide, t_specif *now_basket, int *i)
{
	int				count;
	unsigned char	*s;
	char			filler;

	filler = (now_basket->zero) ? '0' : ' ';
	if (!s_wide)
	{
		*i += now_basket->skip;
		return (write(1, "(null)", 6));
	}
	s = (unsigned char*)s_wide;
	count = 0;
	if (now_basket->minus)
	{
		count += print_str_short(s, now_basket->precis);
		count += put_n_char(' ', now_basket->width - count);
	}
	else
	{
		count += put_n_char(filler, now_basket->width - \
							chars_to_print(s, now_basket->precis));
		count += print_str_short(s, now_basket->precis);
	}
	*i += now_basket->skip;
	return (count);
}

int		print_s_short(unsigned char *s, t_specif *now_basket, int *i)
{
	int		count;
	char	filler;

	filler = (now_basket->zero) ? '0' : ' ';
	if (!s)
		return (print_s_short((unsigned char*)"(null)", now_basket, i));
	count = 0;
	if (now_basket->minus)
	{
		count += print_str_short(s, now_basket->precis);
		count += put_n_char(' ', now_basket->width - count);
	}
	else
	{
		count += put_n_char(filler, now_basket->width - \
							chars_to_print(s, now_basket->precis));
		count += print_str_short(s, now_basket->precis);
	}
	*i += now_basket->skip;
	return (count);
}

int		chars_to_print(unsigned char *s, int precis)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return ((i > precis && precis != -1) ? precis : i);
}

int		print_str_short(unsigned char *s, int precis)
{
	int		i;

	i = 0;
	while (s[i] && (i < precis || precis == -1))
	{
		print_char2(&s[i], &i);
		i++;
	}
	return (i);
}

int		print_char2(unsigned char *format, int *i)
{
	int				len;
	unsigned char	*format2;

	format2 = (unsigned char*)format;
	len = char_len(*format2);
	write(1, format2, len);
	*i = *i + len - 1;
	return (len);
}
