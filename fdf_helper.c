/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:54:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 17:49:01 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	double_abs_div(double a, double b)
{
	double		division;

	division = a / b;
	if (division > 0)
		return (division);
	return (-division);
}

void			ft_mlx_draw_line(t_environment *env
									, t_point *start, t_point *end)
{
	double	error;
	double	delta_error;
	int		y;
	int		x;
	int		increment;

	error = 0;
	delta_error = double_abs_div(end->y - start->y, end->x - start->x);
	y = start->y;
	x = start->x;
	increment = start->x < end->x ? 1 : -1;
	while (x != end->x)
	{
		mlx_pixel_put(env->mlx, env->window, x, y
						, ft_mlx_to_color(255, 255, 255));
		error += delta_error;
		if (error >= 0.5)
		{
			y++;
			error -= 1;
		}
		x += increment;
	}
	mlx_pixel_put(env->mlx, env->window, x, y, ft_mlx_to_color(255, 255, 255));
}
