#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2014/12/05 14:08:02 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			libft.a

CC =			gcc
FLAGS =			-Wall -Werror -Wextra -g

COMPILED =		ft_islower.o \
				ft_isupper.o \
				ft_tolower.o \
				ft_toupper.o \
				ft_isdigit.o \
				ft_isalpha.o \
				ft_isalnum.o \
				ft_isascii.o \
				ft_isprint.o \
				ft_isspace.o \
				ft_strlen.o \
				ft_strnlen.o \
				ft_strchr.o \
				ft_strrchr.o \
				ft_strcmp.o \
				ft_strncmp.o \
				ft_strstr.o \
				ft_strnstr.o \
				ft_strcpy.o \
				ft_strncpy.o \
				ft_strdup.o \
				ft_strcat.o \
				ft_strncat.o \
				ft_strlcat.o \
				ft_memcpy.o \
				ft_memccpy.o \
				ft_memmove.o \
				ft_memcmp.o \
				ft_memset.o \
				ft_memchr.o \
				ft_bzero.o \
				ft_atoi.o \
				ft_memalloc.o \
				ft_memdel.o \
				ft_strnew.o \
				ft_strdel.o \
				ft_strclr.o \
				ft_striter.o \
				ft_striteri.o \
				ft_strmap.o \
				ft_strmapi.o \
				ft_strequ.o \
				ft_strnequ.o \
				ft_strsub.o \
				ft_strjoin.o \
				ft_strtrim.o \
				ft_strsplit.o \
				ft_strsplit_free.o \
				ft_itoa.o \
				ft_putchar.o \
				ft_putstr.o \
				ft_putendl_exit.o \
				ft_putendl.o \
				ft_putnbr.o \
				ft_putchar_fd.o \
				ft_putstr_fd.o \
				ft_putendl_fd.o \
				ft_putnbr_fd.o \
				ft_putstrarr.o \
				ft_putarr.o \
				ft_abs.o \
				get_next_line.o \
				ft_arrlen.o \
				ft_list_create_elem.o \
				ft_list_at.o \
				ft_list_clear.o \
				ft_list_find.o \
				ft_list_find_end.o \
				ft_list_last.o \
				ft_list_push_back.o \
				ft_list_push_front.o \
				ft_list_push_params.o \
				ft_list_remove_if.o \
				ft_list_reverse.o \
				ft_list_size.o \
				ft_min.o \
				ft_max.o \
				ft_ptrswp.o

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
