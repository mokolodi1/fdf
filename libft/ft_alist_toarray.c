/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alist_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:25:29 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/29 16:22:40 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array			*ft_alist_toarray(t_alist *list)
{
	t_array	*array;

	array = malloc(sizeof(t_array*));
	array->length = ft_alist_count(list);
	array->data = malloc(array->length * sizeof(void*));
	ft_memcpy(array->data, list->array, array->length * sizeof(void*));
	return (array);
}
