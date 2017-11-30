/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:09:27 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/07 17:09:28 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *curr;

	if (begin_list1 == NULL || begin_list2 == NULL)
		return ;
	curr = *begin_list1;
	if (!curr)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = begin_list2;
}
