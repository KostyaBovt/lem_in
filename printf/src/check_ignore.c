/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ignore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:45:29 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 15:46:04 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ignore_precis(char c)
{
	if (c == 's' || c == 'S' || c == 'i' || c == 'd' || c == 'b' \
		|| c == 'D' || c == 'u' || c == 'U' || c == 'o' || c == 'v' \
		|| c == 'O' || c == 'x' || c == 'X' || c == 'p' || c == 'w')
		return (0);
	return (1);
}

int		ignore_len(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'o' \
		|| c == 'x' || c == 'X')
		return (0);
	return (1);
}

int		is_cs(char c)
{
	if (c == 'c' || c == 's' || c == 'C' || c == 'S')
		return (1);
	return (0);
}

void	check_ignore(t_specif **basket)
{
	if ((*basket)->plus && (*basket)->space)
		(*basket)->space = 0;
	if ((*basket)->minus && (*basket)->zero && !is_cs((*basket)->type))
		(*basket)->zero = 0;
	if ((*basket)->type != 'i' && (*basket)->type != 'd'
		&& (*basket)->type != 'D')
	{
		(*basket)->plus = 0;
		(*basket)->space = 0;
	}
	if ((*basket)->type != 'o' && (*basket)->type != 'O'
		&& (*basket)->type != 'x' && (*basket)->type != 'X')
		(*basket)->hash = 0;
	if (ignore_precis((*basket)->type))
		(*basket)->precis = -1;
	if (!(((*basket)->type == 'c' || (*basket)->type == 's') && \
		!ft_strncmp2("l", (*basket)->len, 2)))
		if (ignore_len((*basket)->type))
			ft_strcpy2((*basket)->len, "\0\0");
	if ((*basket)->precis != -1 && !is_cs((*basket)->type))
		(*basket)->zero = 0;
}
