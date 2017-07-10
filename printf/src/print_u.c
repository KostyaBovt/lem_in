/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:57:32 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 17:44:31 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**type %q uses two arguments from va_list : BASE , UNSIGNED nay len INTEGER
*/

int		print_uoxq(va_list ap, t_specif *bskt, int *i)
{
	int		b;

	b = get_base(bskt->type, ap);
	if (!(*(bskt->len)) && bskt->type != 'p' \
		&& bskt->type != 'O' && bskt->type != 'U')
		return (print_uoxq_len(va_arg(ap, unsigned int), b, bskt, i));
	if (!ft_strncmp2(bskt->len, "l", 2) || bskt->type == 'U' \
		|| bskt->type == 'O' || bskt->type == 'p')
		return (print_uoxq_len(va_arg(ap, unsigned long), b, bskt, i));
	if (!ft_strncmp2(bskt->len, "ll", 2))
		return (print_uoxq_len(va_arg(ap, unsigned long long), b, bskt, i));
	if (!ft_strncmp2(bskt->len, "h", 2))
		return (print_uoxq_len((unsigned short)va_arg(ap, int), b, bskt, i));
	if (!ft_strncmp2(bskt->len, "hh", 2))
		return (print_uoxq_len((unsigned char)va_arg(ap, int), b, bskt, i));
	if (!ft_strncmp2(bskt->len, "z", 2))
		return (print_uoxq_len(va_arg(ap, size_t), b, bskt, i));
	if (!ft_strncmp2(bskt->len, "j", 2))
		return (print_uoxq_len(va_arg(ap, uintmax_t), b, bskt, i));
	return (0);
}

int		get_base(char c, va_list ap)
{
	if (c == 'u' || c == 'U')
		return (10);
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'q')
		return (va_arg(ap, int));
	return (10);
}
