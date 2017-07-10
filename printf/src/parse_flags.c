/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:14:10 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:14:34 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_flags(const char **inpt, t_specif **basket)
{
	while (**inpt == '-' || **inpt == '+' || **inpt == ' ' \
		|| **inpt == '0' || **inpt == '#')
	{
		if (**inpt == '-')
			if ((*inpt)++)
				(*basket)->minus = '-';
		if (**inpt == '+')
			if ((*inpt)++)
				(*basket)->plus = '+';
		if (**inpt == ' ')
			if ((*inpt)++)
				(*basket)->space = ' ';
		if (**inpt == '#')
			if ((*inpt)++)
				(*basket)->hash = '#';
		if (**inpt == '0')
			if ((*inpt)++)
				(*basket)->zero = '0';
	}
}
