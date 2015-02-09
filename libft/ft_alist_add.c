/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:30:42 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/28 15:42:11 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_alist_add(t_alist *list, void *data)
{
	if (ft_alist_count(list) + 1 > list->length)
		ft_alist_grow_right(list);
	list->last++;
	*(list->last) = data;
}
