/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:31:45 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/21 18:31:47 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../libft/includes/get_next_line.h"
# include "../../printf/includes/ft_printf.h"

typedef struct				s_gnl_list
{
	char					*line;
	struct s_gnl_list		*next;
}							t_gnl_list;

typedef struct				s_path
{
	char					*name;
	void					*room;
	struct s_path			*next;
}							t_path;

typedef struct				s_room
{
	char					*name;
	int						x;
	int						y;
	int						start;
	int						end;
	int						lem;
	int						*lems;
	int						lems_i;
	struct s_path			*nbors;
	struct s_room			*next;
}							t_room;

typedef struct				s_pather
{
	int						num;
	int						qty;
	t_path					*path;
	struct s_pather			*next;
}							t_pather;

typedef struct				s_pather_ptrs
{
	t_pather				*pather;
	struct s_pather_ptrs	*next;
}							t_pather_ptrs;

typedef struct				s_pather_pack
{
	int						moves;
	int						*lems;
	int						pathers_qty;
	int						*pathers_nums;
	int						*pathers_lens;
	t_pather_ptrs			*pathers_ptrs;
	struct s_pather_pack	*next;
}							t_pather_pack;

typedef struct				s_cmnds
{
	t_room					*from;
	t_room					*to;
	struct s_cmnds			*next;
}							t_cmnds;

int							check_inpt(t_gnl_list *inpt, \
							t_room **rooms, int *lems);
int							check_one(int type, t_gnl_list *inpt, \
							t_room **rooms, int *l);
int							check_lems_num(t_gnl_list **inpt, int *lems);
int							over_int(char *str);
long int					ft_atoi_long(char *str);

int							def_type(char *str);
int							is_room(char *str, int *f);
int							is_link(char *str, int *f);

int							prnt_err(char *str);

t_gnl_list					*get_inpt_fd(int fd);

int							check_rooms_exist(char *link, t_room *rooms);
void						get_linked_rooms(char *link, char **room1, \
							char **room2);
int							is_room_exist(char *room, t_room *rooms);
int							add_link(char *link, t_room *rooms);
void						add_nbor(char *room1, char *room2, t_room *rooms);

void						apnd_path(t_path *new_path, t_path **path);
t_path						*make_path_elem(char *room_name, t_room *rooms);
void						make_apnd_path(char *room_name, \
							t_path **curr_path, t_room *rooms);
t_room						*get_room_adrr(char *name, t_room *rooms);
void						del_path(t_path **path);

t_path						*copy_path(t_path *path, t_room *rooms);
int							count_path_elems(t_path *path);
void						print_path(t_path *path);

t_room						*make_new_room(int type, char *name, \
							int cx, int cy);

void						del_rooms(t_room **rooms);
void						apnd_room(t_room *new_room, t_room **rooms);
void						add_room_front(t_room *new_room, t_room **rooms);
void						add_room(int type, char *room, t_room **rooms);

char						*get_room_name(char *room);
void						get_room_xy(char *room, int *x, int *y);
void						print_room(t_room *room, int lems);
void						print_rooms(t_room *rooms, int lems);
void						print_nbors(t_path *path);

int							is_str_digit(char *str);
int							count_chars(char *str, char c);

int							del_char_tab(char ***tab);
int							count_tabs(char **tab);

void						print_gnl(t_gnl_list *list);
void						del_gnl_list(t_gnl_list **head);
void						print_inpt(t_gnl_list *inpt);

int							check_rooms(t_room *room);
int							check_big_rooms(t_room *rooms);
int							check_w_rooms(t_room *rooms);
int							check_w_links(t_room *rooms);
int							check_w_links_one(t_path *nbors);
int							check_l_rooms(t_room *rooms);

int							clear_all(t_gnl_list **inpt, t_room **rooms, \
							t_pather **pather, t_pather_pack **pather_pack);

void						make_pather(t_room *rooms, t_pather **pather);
void						pather_recurs(t_pather **pather, \
							t_path *prv_stp_path, \
							t_room *curr_room, t_room *rooms);
int							exist_in_path(char *name, t_path *path);

void						make_apnd_pather(t_path *new_path, \
							t_pather **pather);
t_pather					*make_new_pather(t_path *new_path);
void						apnd_pather(t_pather *new_pather, \
							t_pather **pather);
void						print_pather(t_pather *pather);
void						del_pather(t_pather **pather);

void						make_pather_packs(t_pather *pather, \
							t_pather_pack **pather_packs);
void						pather_packs_recurs(t_pather *pather, \
							t_pather *curr_pather, \
							t_pather_pack **pather_packs, \
							t_pather_ptrs *prv_pather_ptrs);
void						make_apnd_pth_ptrs(t_pather_ptrs *prv_pather_ptrs, \
							t_pather *curr_pather, \
							t_pather_ptrs **new_pather_ptrs);
void						make_apnd_pth_ptrs2(t_pather *temp_pather, \
							t_pather_ptrs **new_pather_ptrs);

int							pather_in_ptrs(t_pather *pather, \
							t_pather_ptrs *pth_ptrs);
int							path_single(t_pather *pather);
t_pather_ptrs				*make_cross_ptrs(t_pather *pather);

void						make_apnd_pth_pack(t_pather_ptrs *pather_ptrs, \
							t_pather_pack **pather_packs);
t_pather_pack				*make_pather_pack(t_pather_ptrs *pather_ptrs);
void						apnd_pather_pack(t_pather_pack *new_pather_pack, \
							t_pather_pack **pather_packs);
void						fill_pather_pack(t_pather_pack *pather_pack, \
							t_pather_ptrs *pather_ptrs);

void						print_pather_packs(t_pather_pack *pather_packs);
void						print_pathers_ptrs(t_pather_ptrs *pth_ptrs);
void						del_pather_pack(t_pather_pack **pather_packs);
void						print_ints(int *mas, int len);

int							pather_compatible(t_pather *pather, \
							t_pather_ptrs *pather_ptrs);
int							pathes_cross(t_path *path1, t_path *path2);

t_pather_ptrs				*make_new_pth_ptr(t_pather *curr_pather);
void						del_pth_ptrs(t_pather_ptrs **pth_ptrs);
t_pather_ptrs				*copy_pth_ptr(t_pather_ptrs *pth_ptrs);
void						apnd_pth_ptr(t_pather_ptrs *pather_ptrs_elem, \
							t_pather_ptrs **pather_ptrs);
void						print_pth_ptrs(t_pather_ptrs *pth_ptrs);

void						make_pather(t_room *rooms, t_pather **pather);
void						pather_recurs(t_pather **pather, \
							t_path *prv_stp_path, t_room *curr_room, \
							t_room *rooms);
int							exist_in_path(char *name, t_path *path);

void						calc_moves(t_pather_pack *pather_packs, int lems);
void						calc_lems(t_pather_pack *pather_packs, int lems);
void						calc_moves_one(t_pather_pack *pather_packs);

int							get_min_ints(int *mas, int len);
int							get_max_ints(int *mas, int len);
int							ints_sum(int *mas, int len);

int							lems_less_diffs(int *diffs, int qty, int lems);
void						calc_lems_small(int *diffs, \
							t_pather_pack *pather_packs, int lems);
void						get_r_diffs(int *r_diffs, int *diffs, int q_ty);
int							count_not_zero_ints(int *diffs, int q_ty);
void						calc_lems_small_rest(int *r_diffs, int to_reduce, \
							t_pather_pack *pather_packs);

t_pather_pack				*min_moves(t_pather_pack *pather_packs);
void						lems_go(int lems, t_room *rooms, \
							t_pather_pack *pather_pack);
void						init_lems(int lems, t_room *rooms);
int							lems_home(t_room *room, int lems);
t_room						*get_end_room(t_room *rooms);

void						make_cmnds(t_cmnds **cmnds, t_path *path, \
							int path_num, t_pather_pack *pather_pack);
void						apply_cmnds(t_cmnds *cmnds, int path_num, \
							t_pather_pack *pather_pack);
void						apply_cmnd(t_cmnds *cmnds, int path_num, \
							t_pather_pack *pather_pack);
void						apply_cmnd_se(t_cmnds *cmnds, int path_num, \
							t_pather_pack *pather_pack);

void						make_apnd_cmnd(t_cmnds **cmnds, \
							t_room *from, t_room *to);
void						apnd_cmnd(t_cmnds *new_cmnd, t_cmnds **cmnds);
t_cmnds						*make_one_cmnd(t_room *from, t_room *to);
void						del_cmnds(t_cmnds **cmnds);

#endif
