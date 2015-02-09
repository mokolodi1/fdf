/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 19:02:15 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/03 20:18:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_mlx_color_between(int first, int second
										, double percent_first)
{
	return (first * percent_first + second * (1 - percent_first));
}

int				ft_mlx_to_color(int red, int green, int blue)
{
	return (red * 256 * 256 + green * 256 + blue);
}
