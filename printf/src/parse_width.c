/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:18:29 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:19:13 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_width(const char **inpt, t_specif **basket)
{
	int		i;
	long	num;

	if (**inpt == '*')
	{
		(*basket)->width = -1;
		((*basket)->aster)[ft_strlen2((*basket)->aster)] = 'w';
		(*inpt) += 1;
		return ;
	}
	i = 0;
	while (ft_isdigit2((*inpt)[i]))
		i++;
	if (i > 10 || i == 0)
	{
		(*inpt) += i;
		return ;
	}
	num = ft_atoi2(*inpt);
	(*inpt) += i;
	if (num > 2147483647)
		return ;
	(*basket)->width = num;
}

int		ft_atoi2(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + ((int)str[i] - 48);
		i++;
	}
	return (num);
}
