# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 12:59:11 by abmahfou          #+#    #+#              #
#    Updated: 2024/05/21 12:57:15 by abmahfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
YELLOW=\033[1;33m
NC=\033[0m

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= so_long.c \
		   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		   ft_free.c \
		   ft_split.c \
		   errors.c \
		   utils.c \
		   game.c \
		   directions.c

PRINTF = printf/libftprintf.a
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	make -C printf
	$(CC) $(OBJS) $(LIBS) $(PRINTF) $(LIBFT) $(HEADERS) -o $(NAME)
	@echo "                                                             "
	@echo "$(YELLOW)███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ $(NC)"
	@echo "$(YELLOW)██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ $(NC)"
	@echo "$(YELLOW)███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗$(NC)"
	@echo "$(YELLOW)╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║$(NC)"
	@echo "$(YELLOW)███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝$(NC)"
	@echo "$(YELLOW)╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ $(NC)"
	@echo "                                                             "

clean:
	make clean -C printf
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	make fclean -C printf
	rm -rf $(NAME)

re: clean all
	make re -C printf

.PHONY: all, clean, fclean, re, libmlx