/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:34:57 by kbovt             #+#    #+#             */
/*   Updated: 2016/11/24 13:35:47 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	isspc(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' \
	|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int neg_flag;
	int num;

	i = 0;
	neg_flag = 0;
	num = 0;
	while (isspc(str[i]))
		i++;
	if (str[i] == 45)
		neg_flag = 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + ((int)str[i] - 48);
		i++;
	}
	if (neg_flag == 1)
		return (-num);
	else
		return (num);
}
