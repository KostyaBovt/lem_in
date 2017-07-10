/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:01:40 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:01:41 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_inpt(t_gnl_list *inpt, t_room **rooms, int *lems)
{
	int		type;
	int		l;

	l = 0;
	if (!inpt)
		return (prnt_err("no input at all"));
	if (!check_lems_num(&inpt, lems))
		return (0);
	while (inpt)
	{
		type = def_type(inpt->line);
		if (!check_one(type, inpt, rooms, &l))
			return (0);
		inpt = (type == 2 || type == 3) ? (inpt->next)->next : inpt->next;
	}
	if (!check_rooms(*rooms))
		return (0);
	if (!l)
		return (prnt_err("no links entered at all"));
	return (1);
}

int			check_one(int type, t_gnl_list *inpt, t_room **rooms, int *l)
{
	if (!type)
		return (0);
	if ((type == 2 || type == 3) && !(inpt->next))
		return (prnt_err("no room after ##"));
	if ((type == 2 || type == 3) && def_type((inpt->next)->line) != 4)
		return (prnt_err("not a room after ##"));
	if ((type == 2 || type == 3 || type == 4) && *l)
		return (prnt_err("you cann`t iput room after links"));
	if ((type == 2 || type == 3) && def_type((inpt->next)->line) == 4)
		add_room(type, (inpt->next)->line, rooms);
	if (type == 4)
		add_room(type, inpt->line, rooms);
	if (type == 5 && !check_rooms_exist(inpt->line, *rooms))
		return (prnt_err("you link not existing room(s)"));
	if (type == 5)
		if (++(*l))
			if (!add_link(inpt->line, *rooms))
				return (0);
	return (1);
}

int			check_lems_num(t_gnl_list **inpt, int *lems)
{
	int		i;
	char	*str;

	str = (*inpt)->line;
	i = -1;
	if (!str[0])
		return (prnt_err("no lems number entered at all"));
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (prnt_err("lems num contains non digits"));
	if (over_int(str))
		return (prnt_err("lems num is over than integer"));
	*lems = ft_atoi(str);
	if (*lems == 0)
		return (prnt_err("lems num must be greater than 0"));
	(*inpt) = (*inpt)->next;
	return (1);
}

int			over_int(char *str)
{
	long int	num;

	if (ft_strlen(str) > 10)
		return (1);
	num = ft_atoi_long(str);
	if (num > 2147483647)
		return (1);
	if (num < -2147483648)
		return (1);
	return (0);
}

long int	ft_atoi_long(char *str)
{
	int			i;
	long int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + ((long int)str[i] - 48);
		i++;
	}
	return (num);
}
