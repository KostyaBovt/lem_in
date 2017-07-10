#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbovt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:40:11 by kbovt             #+#    #+#              #
#    Updated: 2017/03/21 18:40:13 by kbovt            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

VPATH = ./lem_in_f/src
NAME = lem_in
LIB = libft.a
LIB_PATH = ./libft
PRINTF = printf.a
PRINTF_PATH = ./printf
SRC = make_cmnds.c cmnds.c lems_go.c ints.c calc_moves.c \
calc_moves2.c pather_ptrs2.c check_rooms2.c \
pather.c make_pather.c pather_pack.c pather_pack2.c \
pather_ptrs.c make_pather_packs_main.c clear_all.c gnl.c \
check_rooms.c check_inpt.c def_type.c error.c get_inpt.c \
link.c main_lem_in.c path.c path2.c room2.c room.c str.c \
tab.c
OBJ = $(subst .c,.o,$(SRC))

.PHONY: all clean fclean re cleano

all: $(NAME)

$(NAME): $(LIB) $(PRINTF) $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(PRINTF) $(LIB)

$(OBJ): $(SRC)
	gcc -Wall -Wextra -Werror -c $^

$(LIB) :
	@make -C $(LIB_PATH)
	@make clean -C $(LIB_PATH)
	mv $(LIB_PATH)/$(LIB) ./

$(PRINTF) :
	@make -C $(PRINTF_PATH)
	@make clean -C $(PRINTF_PATH)
	mv $(PRINTF_PATH)/$(PRINTF) ./

cleano:
	/bin/rm -f $(OBJ)

clean: cleano
	/bin/rm -f $(LIB)
	/bin/rm -f $(PRINTF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
