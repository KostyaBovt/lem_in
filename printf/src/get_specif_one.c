/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specif_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:04:17 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:07:39 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_specif		*get_specif_one(const char *inpt, int *i)
{
	t_specif	*basket;
	const char	*temp;
	const char	*parse_temp;

	temp = inpt;
	basket = empty_basket();
	while (*inpt)
	{
		parse_temp = inpt;
		parse_flags(&inpt, &basket);
		parse_width(&inpt, &basket);
		parse_precis(&inpt, &basket);
		parse_len(&inpt, &basket);
		if (parse_temp == inpt)
			break ;
	}
	parse_type(&inpt, &basket);
	basket->skip = inpt - temp;
	*i = *i + (inpt - temp);
	check_ignore(&basket);
	return (basket);
}

t_specif		*empty_basket(void)
{
	t_specif	*new_basket;

	new_basket = (t_specif*)malloc(sizeof(t_specif));
	fill_aster_line(new_basket->aster);
	new_basket->minus = 0;
	new_basket->plus = 0;
	new_basket->space = 0;
	new_basket->hash = 0;
	new_basket->zero = 0;
	new_basket->width = -1;
	new_basket->precis = -1;
	ft_strcpy2(new_basket->len, "\0\0");
	new_basket->type = 0;
	new_basket->next = NULL;
	new_basket->skip = 0;
	return (new_basket);
}

void			fill_aster_line(char *aster)
{
	int			i;

	i = -1;
	while (++i < 100)
		aster[i] = '\0';
}
