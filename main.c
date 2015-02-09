/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:20:59 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 17:33:20 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_ints(char **split, size_t split_length, int *ints)
{
	size_t		i;

	i = 0;
	while (i < split_length)
	{
		ints[i] = ft_atoi(split[i]);
		i++;
	}
}

static int		do_line(int fd, int **ints, size_t *width)
{
	char	*line;
	int		read_ret;
	char	**split;

	read_ret = get_next_line(fd, &line);
	if (read_ret == -1)
		ft_putendl_exit("Error reading file", 1);
	split = ft_strsplit(line, INPUT_SPLIT_ON);
	*width = ft_arrlen(split);
	*ints = malloc(*width * sizeof(int));
	set_ints(split, *width, *ints);
	ft_strsplit_free(split);
	free(line);
	return (read_ret);
}

static void		process_rest(int fd, t_list **int_list
								, size_t expect_width
								, size_t *height)
{
	int			*curr_ints;
	size_t		width;

	while (do_line(fd, &curr_ints, &width))
	{
		if (width != expect_width)
			ft_putendl_exit("One of the lines is not like the others!", 1);
		ft_list_push_back(int_list, curr_ints);
		(*height)++;
	}
}

static t_intarr	*convert_to_intarr(t_list **int_list
									, size_t width, size_t height)
{
	t_intarr	*array;
	size_t		i;
	t_list		*this;

	array = malloc(sizeof(t_intarr));
	array->height = height;
	array->width = width;
	array->data = malloc(height * sizeof(int*));
	i = 0;
	this = *int_list;
	while (this != NULL)
	{
		array->data[i] = this->data;
		this = this->next;
		i++;
	}
	ft_list_clear(int_list);
	return (array);
}

int				main(int argc, char **argv)
{
	int			fd;
	size_t		width;
	size_t		height;
	int			*curr_ints;
	t_list		*int_list;

	if (argc != 2)
		ft_putendl_exit("Program must have one argument. (./fdf <file>)", 1);
	fd = open(argv[1], O_RDONLY);
	do_line(fd, &curr_ints, &width);
	if (width <= 0)
		ft_putendl_exit("Must have at least one line of data\n", 1);
	ft_list_push_back(&int_list, curr_ints);
	height = 1;
	process_rest(fd, &int_list, width, &height);
	fdf(convert_to_intarr(&int_list, width, height), PIXEL_WIDTH, PIXEL_HEIGHT);
	return (0);
}
