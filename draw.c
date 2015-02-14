/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 17:03:41 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/14 18:00:04 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		calculate_points(t_environment *env
									, t_point points[env->array->height
														* env->array->width])
{
	int		row;
	int		column;
	int		index;
	double	z_mult;

	z_mult = -1;
	row = 0;
	while (row < env->array->height)
	{
		column = 0;
		while (column < env->array->width)
		{
			index = row * env->array->width + column;
			points[index].x = env->left_const * column
									- env->right_const * row
									+ env->width / 2;
			points[index].y = z_mult * env->array->data[row][column]
									+ env->left_const / 2 * column
									+ env->right_const / 2 * row;
			points[index].z = env->array->data[row][column];
			column++;
		}
		row++;
	}
}

static void		draw_horizontal(t_environment *env
								, t_point points[env->array->height
													* env->array->width]
								, int y)
{
	int	i;

	i = 0;
	while (i < env->array->width - 1)
	{
		mlx_draw_line(env
						, &(points[y * env->array->width + i])
						, &(points[y * env->array->width + i + 1]));
		i++;
	}
}

static void		draw_vertical(t_environment *env
								, t_point points[env->array->height
													* env->array->width]
								, int x)
{
	int	i;

	i = 0;
	while (i < env->array->height - 1)
	{
		mlx_draw_line(env
						, &(points[i * env->array->width + x])
						, &(points[(i + 1) * env->array->width + x]));
		i++;
	}
}

void			draw(t_environment *env)
{
	int			i;
	t_point		points[env->array->height * env->array->width];

	calculate_points(env, points);
	i = 0;
	if (env->array->height == 1 && env->array->width == 1)
		mlx_draw_line(env, &points[0], &points[0]);
	while (i < env->array->height)
	{
		draw_horizontal(env, points, i);
		i++;
	}
	i = 0;
	while (i < env->array->width)
	{
		draw_vertical(env, points, i);
		i++;
	}
}
