# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 08:01:27 by ikhadem           #+#    #+#              #
#    Updated: 2021/01/07 15:08:39 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := TermCaped

CC := gcc

SOURCES := sources

IO := $(SOURCES)/IO

STRING := $(SOURCES)/string

TERMINAL := $(SOURCES)/terminal

SRC :=	main.c \
		$(IO)/ft_putchar.c \
		$(IO)/ft_putstr.c \
		$(STRING)/str_manip.c \
		$(TERMINAL)/terminal_setup.c \
		$(TERMINAL)/ft_capabilities.c \
		$(TERMINAL)/move_cursor.c \
		$(TERMINAL)/terminal_clear_screen.c \
		$(TERMINAL)/insert_mode.c \
		$(TERMINAL)/terminal_putstr.c \
		$(TERMINAL)/delete_mode.c

OBJ := $(SRC:.c=.o)

HEADERS := -I Headers

LIBS := -lncurses -ltermcap

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(HEADERS) $(LIBS) $(OBJ) -o $(NAME)
			@echo "$(NAME) : Finished Compilation"

%.o : %.c
			@$(CC) -c $(HEADERS) $< -o $@

clean:
			@rm -f $(OBJ)
			@echo "$(NAME) : Removed Objects"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(NAME) : Removed Binary"

re:			fclean all