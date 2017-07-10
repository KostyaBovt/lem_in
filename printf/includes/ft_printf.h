/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:17:00 by kbovt             #+#    #+#             */
/*   Updated: 2017/02/13 18:23:20 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

typedef unsigned long long	t_ull;
typedef unsigned char		t_uc;
typedef long long int		t_lli;
typedef const char			t_cc;

typedef struct		s_specif
{
	char			aster[100];
	char			minus;
	char			plus;
	char			space;
	char			hash;
	char			zero;
	int				width;
	int				precis;
	char			len[3];
	char			type;
	struct s_specif *next;
	int				skip;
}					t_specif;

typedef struct		s_list2
{
	void			*content;
	size_t			content_size;
	struct s_list2	*next;
}					t_list2;

/*
** lib_funcs.c
*/
int					ft_isdigit2(int c);
int					ft_strncmp2(t_cc *s1, t_cc *s2, int n);
int					ft_strlen2(t_cc *str);
char				*ft_strcpy2(char *dst, t_cc *src);
char				*ft_strchr2(t_cc *s, int c);

/*
** ft_printf.c.c
*/
int					ft_printf(t_cc *format, ...);

/*
** get_specif.c
*/
int					push_back(t_specif **head_specif, t_specif *new_specif);
int					get_specif_list(t_cc *inpt, t_specif **head_specif);
void				del_specif(t_specif **head_specif);

/*
** get_specif_one.c
*/
t_specif			*get_specif_one(t_cc *inpt, int *i);
t_specif			*empty_basket(void);
void				fill_aster_line(char *aster);

/*
** parse_flags.c
*/
void				parse_flags(t_cc **inpt, t_specif **basket);

/*
** parse_width.c
*/
void				parse_width(t_cc **inpt, t_specif **basket);
int					ft_atoi2(t_cc *str);

/*
** parse_precis.c
*/
void				parse_precis_wc(t_cc **inpt, t_specif **basket);
void				parse_precis_zr(t_cc **inpt, t_specif **basket);
void				parse_precis(t_cc **inpt, t_specif **basket);

/*
** parse_len.c
*/
int					get_len(char *str);
int					start_len(char c);
void				fill_len_flags(char len_flags[7][3]);
void				parse_len(t_cc **inpt, t_specif **basket);

/*
** parse_type.c
*/
void				parse_type(t_cc **inpt, t_specif **basket);

/*
** check_ignore.c
*/
int					ignore_precis(char c);
int					ignore_len(char c);
int					is_cs(char c);
void				check_ignore(t_specif **basket);

/*
** print_format.c
*/
int					print_format(t_cc *format, va_list ap, t_specif *basket);
int					print_char(t_cc *format, int *i);
int					char_len(t_uc c);
int					get_n_bit(t_uc c, int n);

/*
** print_one.c
*/
int					print_one(va_list ap, t_specif *bskt, int *i);
void				process_wildcard(va_list ap, t_specif *bskt);
int					print_nothing(t_specif *bskt, int *i);
int					print_undef(t_specif *bskt, int *i);

/*
** print_c.c
*/
int					print_c(va_list ap, t_specif *bskt, int *i);
int					print_c_wide(wchar_t c, t_specif *bskt, int *i);
int					print_c_short(t_uc c, t_specif *bskt, int *i);
int					put_n_char(char c, int n);

/*
** print_s.c
*/
int					print_s(va_list ap, t_specif *bskt, int *i);

/*
** print_s_next.c
*/
int					print_s_wide(t_uc *s_wide, t_specif *bskt, int *i);
int					print_s_short(t_uc *s, t_specif *bskt, int *i);
int					chars_to_print(t_uc *s, int precis);
int					print_str_short(t_uc *s, int precis);
int					print_char2(t_uc *format, int *i);

/*
** print_i.c
*/
int					print_i(va_list ap, t_specif *bskt, int *i);

/*
** print_i_len.c
*/
int					print_i_len(t_lli num, t_specif *bskt, int *i);
int					count_spac_b(t_lli num, t_specif *bskt);
int					print_sign(t_lli num, t_specif *bskt);
int					count_zeros(t_lli num, t_specif *bskt);
int					count_spac_a(t_lli num, t_specif *bskt);

/*
** print_i_len_num.c
*/
int					num_len(t_lli num, int base);
t_lli				num_delim(t_lli num, int base);
t_lli				mod(t_lli num);
int					print_num(t_lli num, int base, t_specif *bskt);

/*
** print_u.c
*/
int					print_uoxq(va_list ap, t_specif *bskt, int *i);
int					get_base(char c, va_list ap);

/*
** print_u_len.c
*/
int					print_uoxq_len(t_ull num, int base, t_specif *bskt, int *i);
int					count_spac_bu(t_ull num, int base, t_specif *bskt);
int					print_hash(t_ull num, int base, t_specif *bskt);
int					count_zeros_u(t_lli num, int base, t_specif *bskt);
int					count_spac_au(t_ull num, int base, t_specif *bskt);

/*
** print_u_len_num.c
*/
int					num_len_u(t_ull num, int base);
t_ull				num_delim_u(t_ull num, int base);
int					print_null(t_specif *bskt);
int					print_num_u(t_ull num, int base, t_specif *bskt);

/*
** print_bits.c
*/
int					print_bits(void *ptr, t_specif *bskt, int *i);
void				print_char_bits(t_uc c);

/*
** print_memory.c
*/
int					print_hex(t_uc c);
int					print_dots(t_uc **tmp, int flag, int len);
int					print_memory_sub(t_uc *addr, int size);
int					print_memory(void *addr, t_specif *bskt, int *i);

/*
** print_vtab.c
*/
int					print_vtab(char **vtab, int tabs, t_specif *bskt, int *i);

/*
** print_lst.c
*/
int					print_lst(t_list2 *list, int limit, t_specif *bskt, int *i);
t_uc				*ft_strncpy2(t_uc *dst, t_uc *src, size_t len);

#endif
