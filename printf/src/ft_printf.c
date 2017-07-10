/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:58:58 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 15:59:02 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_specif	*specif_list;
	int			ret_print;

	ret_print = 0;
	if (!(*format) || !format)
		return (0);
	va_start(ap, format);
	specif_list = NULL;
	get_specif_list(format, &specif_list);
	ret_print = print_format(format, ap, specif_list);
	va_end(ap);
	del_specif(&specif_list);
	return (ret_print);
}
