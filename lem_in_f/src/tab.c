/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:08:41 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:08:42 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		del_char_tab(char ***tab)
{
	int		i;

	i = -1;
	while ((*tab)[++i])
		free((*tab)[i]);
	free(*tab);
	*tab = NULL;
	return (0);
}

int		count_tabs(char **tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		count++;
		i++;
	}
	return (count);
}
