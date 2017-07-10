/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:02:48 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:02:49 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** 0 - Error type;
** 1 - Comment;
** 2 - Modify command ##start;
** 3 - Modify command ##end;
** 4 - Room;
** 5 - Links;
*/

int		def_type(char *str)
{
	int		f;
	int		r;

	f = 0;
	if (str[0] == '\0')
		return (prnt_err("FATAL MORTAL INPUT ERROR"));
	if (!ft_strcmp(str, "##start"))
		return (2);
	if (!ft_strcmp(str, "##end"))
		return (3);
	if (!ft_strncmp(str, "#", 1))
		return (1);
	r = is_room(str, &f) + is_link(str, &f);
	if (f == 2)
		return (prnt_err("FATAL MORTAL INPUT ERROR"));
	return (r);
}

/*
** 4 - Room;
*/

int		is_room(char *str, int *f)
{
	char	**room;

	if (count_chars(str, ' ') != 2)
	{
		(*f)++;
		return (0);
	}
	room = ft_strsplit(str, ' ');
	if (count_tabs(room) != 3)
		if (!del_char_tab(&room))
			return (prnt_err("not full room info entered!"));
	if (!room[0][0] || !room[1][0] || !room[2][0])
		if (!del_char_tab(&room))
			return (prnt_err("not full room info entered"));
	if (!is_str_digit(room[1]) || !is_str_digit(room[2]))
		if (!del_char_tab(&room))
			return (prnt_err("room coordinates is not integers"));
	if (over_int(room[1]) || over_int(room[2]))
	{
		del_char_tab(&room);
		return (prnt_err("room coordinates is over integer"));
	}
	del_char_tab(&room);
	return (4);
}

/*
** 5 - Links;
*/

int		is_link(char *str, int *f)
{
	if (count_chars(str, ' '))
	{
		(*f)++;
		return (0);
	}
	if (count_chars(str, '-') != 1)
	{
		(*f)++;
		return (0);
	}
	return (5);
}
