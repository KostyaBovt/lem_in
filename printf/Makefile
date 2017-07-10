NAME = printf.a
VPATH = src:includes
SRC = lib_func.c \
ft_printf.c \
get_specif.c \
get_specif_one.c \
parse_flags.c \
parse_width.c \
parse_precis.c \
parse_len.c \
parse_type.c \
check_ignore.c \
print_format.c \
print_one.c \
print_c.c \
print_s.c \
print_s_next.c \
print_i.c \
print_i_len.c \
print_i_len_num.c \
print_u.c \
print_u_len.c \
print_u_len_num.c \
print_bits.c \
print_memory.c \
print_vtab.c \
print_lst.c
HEAD = ft_printf.h
OBJS = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $?
	ranlib $@

$(OBJS): $(HEAD)

.c.o: $(SRC)
	gcc -Wall -Wextra -Werror -I ./includes -c $<

clean:
	/bin/rm -f $(OBJS)

dellib:
	/bin/rm -f $(NAME)

fclean: clean dellib

re: fclean all