/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:03:28 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:03:29 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_min_ints(int *mas, int len)
{
	int		min;
	int		i;

	min = mas[0];
	i = -1;
	while (++i < len)
		if (mas[i] < min)
			min = mas[i];
	return (min);
}

int		get_max_ints(int *mas, int len)
{
	int		max;
	int		i;

	max = mas[0];
	i = -1;
	while (++i < len)
		if (mas[i] > max)
			max = mas[i];
	return (max);
}

int		ints_sum(int *mas, int len)
{
	int		sum;
	int		i;

	sum = 0;
	i = -1;
	while (++i < len)
		sum += mas[i];
	return (sum);
}

void	print_ints(int *mas, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		ft_printf("{%i} ", mas[i]);
}
