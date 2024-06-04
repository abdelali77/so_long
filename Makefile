# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 12:59:11 by abmahfou          #+#    #+#              #
#    Updated: 2024/06/04 10:08:43 by abmahfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	   = so_long
NAME_BONUS = so_long_bonus
CC		   = cc
CFLAGS	   = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	   = ~/MLX42
VIVID_RED=\033[38;2;226;3;56m
NC=\033[0m

HEADERS	= -I ./include -I $(LIBMLX)/include
HEADER  = so_long.h

LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= so_long.c ft_free.c ft_split.c errors.c utils.c game.c directions.c fill_map.c check_map.c \
		  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_BONUS = bonus/so_long_bonus.c bonus/check_map_bonus.c bonus/directions_bonus.c bonus/errors_bonus.c \
			 bonus/fill_map_bonus.c bonus/ft_free_bonus.c bonus/ft_split_bonus.c bonus/game_bonus.c \
			 bonus/utils_bonus.c bonus/ft_itoa_bonus.c bonus/hooks_bonus.c \
			 get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 

PRINTF = printf/libftprintf.a
OBJS   = ${SRCS:.c=.o}
OBJS_B = ${SRCS_BONUS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@make -C printf
	@$(CC) $(OBJS) $(LIBS) $(PRINTF) $(HEADERS) -o $(NAME)
	@echo "                                                             "
	@echo "$(VIVID_RED)  ██████  ▒█████   ██▓     ▒█████   ███▄    █   ▄████ $(NC)"
	@echo "$(VIVID_RED)▒██    ▒ ▒██▒  ██▒▓██▒    ▒██▒  ██▒ ██ ▀█   █  ██▒ ▀█▒$(NC)"
	@echo "$(VIVID_RED)░ ▓██▄   ▒██░  ██▒▒██░    ▒██░  ██▒▓██  ▀█ ██▒▒██░▄▄▄░$(NC)"
	@echo "$(VIVID_RED)  ▒   ██▒▒██   ██░▒██░    ▒██   ██░▓██▒  ▐▌██▒░▓█  ██▓$(NC)"
	@echo "$(VIVID_RED)▒██████▒▒░ ████▓▒░░██████▒░ ████▓▒░▒██░   ▓██░░▒▓███▀▒$(NC)"
	@echo "$(VIVID_RED)▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒ $(NC)"
	@echo "$(VIVID_RED)░ ░▒  ░ ░  ░ ▒ ▒░ ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░ $(NC)"
	@echo "$(VIVID_RED)░  ░  ░  ░ ░ ░ ▒    ░ ░   ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░ $(NC)"
	@echo "$(VIVID_RED)      ░      ░ ░      ░  ░    ░ ░           ░       ░ $(NC)"
	@echo "                                                             "


$(NAME_BONUS): libmlx $(OBJS_B)
	@make -C printf
	@$(CC) $(OBJS_B) $(LIBS) $(PRINTF) $(HEADERS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	@make clean -C printf
	@rm -rf $(OBJS) $(OBJS_B)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make fclean -C printf
	@rm -rf $(NAME) $(NAME_BONUS)

re: clean all
	@make re -C printf

.PHONY: all, clean, fclean, re, bonus, libmlx