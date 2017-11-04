/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:21:03 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:27:09 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lst_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL)
		return (NULL);
	while (begin_list)
	{
		if (!(*cmp)(begin_list->content, data_ref))
			break ;
		begin_list = begin_list->next;
	}
	return (begin_list);
}
