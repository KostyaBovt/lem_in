#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbovt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 12:34:09 by kbovt             #+#    #+#              #
#    Updated: 2016/12/03 20:26:07 by kbovt            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

VPATH = ./src
NAME = libft.a
SOURCES = ft_itoa.c ft_atoi.c ft_lstadd.c ft_memchr.c ft_putchar_fd.c \
ft_strchr.c ft_striteri.c ft_strncpy.c ft_strtrim.c ft_bzero.c ft_lstdel.c \
ft_memcmp.c ft_putendl.c ft_strclr.c ft_strjoin.c ft_strnequ.c ft_tolower.c \
ft_isalnum.c ft_lstdelone.c ft_memcpy.c ft_putendl_fd.c ft_strcmp.c \
ft_strlcat.c ft_strnew.c ft_toupper.c ft_isalpha.c ft_lstiter.c	ft_memdel.c \
ft_putnbr.c	ft_strcpy.c	ft_strlen.c	ft_strnstr.c ft_isascii.c ft_lstmap.c \
ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strrchr.c ft_isdigit.c ft_lstnew.c \
ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c ft_strsplit.c ft_isprint.c \
ft_memalloc.c ft_memset.c ft_putstr_fd.c ft_strequ.c ft_strncat.c \
ft_strstr.c ft_memccpy.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c \
ft_strsub.c get_next_line.c get_next_line2.c
OBJECTS = $(subst .c,.o,$(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECT): $(SOURCES)
	gcc -Wall -Wextra -Werror -c $(SOURCES) 

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all