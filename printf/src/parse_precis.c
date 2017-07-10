/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:16:31 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:17:33 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_precis_wc(const char **inpt, t_specif **basket)
{
	(*basket)->precis = -1;
	((*basket)->aster)[ft_strlen2((*basket)->aster)] = 'p';
	(*inpt) += 2;
	return ;
}

void	parse_precis_zr(const char **inpt, t_specif **basket)
{
	(*basket)->precis = 0;
	(*inpt) += 1;
	return ;
}

void	parse_precis(const char **inpt, t_specif **basket)
{
	int		i;
	long	num;

	if (**inpt != '.')
		return ;
	if ((*inpt)[1] == '*')
		return (parse_precis_wc(inpt, basket));
	if (!ft_isdigit2((*inpt)[1]))
		return (parse_precis_zr(inpt, basket));
	i = 1;
	while (ft_isdigit2((*inpt)[i]))
		i++;
	if (i > 11)
	{
		(*inpt) += i;
		return ;
	}
	num = ft_atoi2(*inpt + 1);
	(*inpt) += i;
	if (num > 2147483647)
		return ;
	(*basket)->precis = num;
}
