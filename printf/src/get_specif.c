/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:09:36 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 16:11:24 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		push_back(t_specif **head_specif, t_specif *new_specif)
{
	t_specif *temp1;

	if (new_specif == NULL)
		return (0);
	if (*head_specif == NULL)
	{
		*head_specif = new_specif;
		return (1);
	}
	temp1 = *head_specif;
	while ((*head_specif)->next != NULL)
		*head_specif = (*head_specif)->next;
	(*head_specif)->next = new_specif;
	*head_specif = temp1;
	return (1);
}

int		get_specif_list(const char *inpt, t_specif **head_specif)
{
	int		i;

	if (!ft_strchr2(inpt, '%'))
		return (0);
	i = -1;
	while (inpt[++i])
	{
		if (inpt[i] == '%')
			if (!push_back(head_specif, get_specif_one(&inpt[i + 1], &i)))
				return (-1);
	}
	return (1);
}

void	del_specif(t_specif **head)
{
	t_specif *buf;
	t_specif *elem;

	buf = *head;
	while (buf)
	{
		elem = buf;
		buf = buf->next;
		free(elem);
	}
}
/*
**void print_specif_list(t_specif *specif)
**{
**	if (!specif)
**	{
**		printf ("empty specif list!\n pointer to specif : %p\n", specif);
**		return ;
**	}
**	int count = 1;
**	while (specif)
**	{
**		printf("specificator #%i\n", count);
**		printf("minus_ : |%c|\n", specif->minus);
**		printf("plus__ : |%c|\n", specif->plus);
**		printf("space_ : |%c|\n", specif->space);
**		printf("hash__ : |%c|\n", specif->hash);
**		printf("zero__ : |%c|\n", specif->zero);
**		printf("width_ : |%i|\n", specif->width);
**		printf("precis : |%i|\n", specif->precis);
**		printf("len___ : |%s|\n", specif->len);
**		printf("type__ : |%c|\n", specif->type);
**		printf("skip__ : |%i|\n", specif->skip);
**		printf("next__ : |%p|\n\n", specif->next);
**		specif = specif->next;
**		count++;
**	}
**}
*/
