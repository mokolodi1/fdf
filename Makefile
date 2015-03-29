#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2015/03/21 20:07:03 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			fdf

CC =			gcc
FLAGS =			-Wall -Werror -Wextra
LIBFT =			"libft/"
X11 =			"/usr/X11/lib"
MLX =			"minilibx_macos/"

INC_FLAGS =		-I $(LIBFT) -I $(MLX)
LIB_FLAGS =		-L $(LIBFT) -L $(X11) -L $(MLX) -lft -lmlx \
				-framework OpenGL -framework AppKit

COMPILED =		main.o \
				handle_fdf.o \
				draw.o \
				mlx_draw_line.o \
				mlx_rgb_to_color.o \
				expose_hook.o \
				mouse_hook.o \
				key_hook.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(MLX)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_FLAGS) $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) $(INC_FLAGS) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
