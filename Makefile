#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2014/12/05 14:12:20 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			fdf

CC =			gcc
FLAGS =			-Wall -Werror -Wextra
LIBFT =			"libft/"
X11 =			"/usr/X11/lib"

INC_FLAGS =		-I $(LIBFT)
LIB_FLAGS =		-L $(LIBFT) -L $(X11)

COMPILED =		main.o \
				fdf.o \
				ft_mlx.o \
				fdf_mlx_draw_line.o \
				ft_mlx_hooks.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_FLAGS) -lft -lmlx -lXext -lX11 $(COMPILED)
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