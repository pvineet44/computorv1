# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vparekh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 18:47:15 by vparekh           #+#    #+#              #
#*   Updated: 2020/09/24 20:15:57 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

BINARY = computor

LIBFT = ./libft/libft.a
LIBFT_SRC := $(wildcard libft/*.c)
LIBFT_OBJ := $(patsubst libft/%.c, libft/%.o, $(LIBFT_SRC))

COMP = gcc -Wall -Wextra -fsanitize=address -g3
# COMP = gcc -Wall -Wextra -g3
INCLUDES = -Iincludes -Llibft -lft
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))
GREEN='\033[01;32m'
RESET='\033[00m'

all: $(BINARY)

$(BINARY): $(LIBFT) $(MLX) $(OBJ)
	@echo  "$(GREEN).................Making computorv1................ $(RESET)"
	$(COMP) $(INCLUDES) $(OBJ) $(LIBFT) -o $(BINARY)

$(LIBFT): $(LIBFT_OBJ)
	@echo  "$(GREEN).................Making Libft.................... $(RESET)"
	ar rcs $(LIBFT) $(LIBFT_OBJ)

libft/%.o: libft/%.c
	$(COMP) -Iincludes -c $< -o $@

obj/%.o: src/%.c
	mkdir -p obj
	$(COMP) -Iincludes -c $< -o $@
norme:
	norminette src/*
	norminette includes/*

clean: 
		rm -rf libft/*.o obj/*

fclean: clean
	rm -rf $(BINARY) *.dSYM $(LIBFT)

re: fclean all
