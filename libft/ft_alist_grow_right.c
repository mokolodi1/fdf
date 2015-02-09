/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alist_grow_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:33:20 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/28 15:42:38 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_alist_grow_right(t_alist *list)
{
	void	**new_array;
	size_t	new_length;

	new_length = list->length * ALIST_GROW_MULT;
	while (ALIST_GROW_MULT * new_length < list->length + ALIST_GROW_MIN)
		new_length++;
	new_array = malloc(new_length * sizeof(void*));
	ft_memcpy(new_array
				, list->array
				, ft_alist_count(list) * sizeof(void*));
	list->last = new_array + (list->last - list->array);
	free(list->array);
	list->array = new_array;
	list->length = new_length;
}
