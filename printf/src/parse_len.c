/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:15:02 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:15:51 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_len(char *str)
{
	if (!(*str))
		return (0);
	if (!ft_strncmp2(str, "hh", 2))
		return (1);
	if (!ft_strncmp2(str, "h", 1))
		return (2);
	if (!ft_strncmp2(str, "ll", 2))
		return (4);
	if (!ft_strncmp2(str, "l", 1))
		return (3);
	if (!ft_strncmp2(str, "z", 1))
		return (5);
	if (!ft_strncmp2(str, "j", 1))
		return (6);
	return (0);
}

int		start_len(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

void	fill_len_flags(char len_flags[7][3])
{
	int i;

	i = -1;
	while (++i < 7)
	{
		len_flags[i][0] = '\0';
		len_flags[i][1] = '\0';
		len_flags[i][2] = '\0';
	}
	len_flags[0][0] = 'l';
	len_flags[0][1] = 'l';
	len_flags[1][0] = 'l';
	len_flags[2][0] = 'h';
	len_flags[2][1] = 'h';
	len_flags[3][0] = 'h';
	len_flags[4][0] = 'j';
	len_flags[5][0] = 'z';
}

void	parse_len(const char **inpt, t_specif **basket)
{
	char	g_len_flags[7][3];
	int		i;

	fill_len_flags(g_len_flags);
	while (start_len(**inpt))
	{
		i = -1;
		while (g_len_flags[++i][0])
			if (!ft_strncmp2(g_len_flags[i], *inpt, ft_strlen2(g_len_flags[i])))
			{
				(*inpt) += ft_strlen2(g_len_flags[i]);
				if (get_len(g_len_flags[i]) > get_len((*basket)->len))
					ft_strcpy2((*basket)->len, g_len_flags[i]);
				break ;
			}
	}
}
