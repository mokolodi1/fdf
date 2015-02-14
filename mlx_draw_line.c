/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:23:47 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/14 17:55:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			setup(t_drawer *drawer, t_point *start, t_point *end)
{
	drawer->x_start = start->x;
	drawer->y_start = start->y;
	drawer->x_end = end->x;
	drawer->y_end = end->y;
	drawer->x_slope = abs(drawer->x_end - drawer->x_start);
	drawer->y_slope = abs(drawer->y_end - drawer->y_start);
	drawer->error = (drawer->x_slope > drawer->y_slope ?
						drawer->x_slope : -drawer->y_slope) / 2;
}

static void			x_move(t_drawer *drawer)
{
	drawer->error -= drawer->y_slope;
	drawer->x_start += drawer->x_start < drawer->x_end ? 1 : -1;
}

static void			y_move(t_drawer *drawer)
{
	drawer->error += drawer->x_slope;
	drawer->y_start += drawer->y_start < drawer->y_end ? 1 : -1;
}

void				mlx_draw_line(t_environment *env
										, t_point *start, t_point *end)
{
	t_drawer		drawer;

	setup(&drawer, start, end);
	while (1)
	{
		mlx_pixel_put(env->mlx, env->window, drawer.x_start, drawer.y_start
					  , mlx_rgb_to_color(255, 255, 255));
		if (drawer.x_start == drawer.x_end && drawer.y_start == drawer.y_end)
			break ;
		if (drawer.error > -drawer.x_slope)
			x_move(&drawer);
		if (drawer.error < drawer.y_slope)
			y_move(&drawer);
	}
}
