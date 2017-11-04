/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:32:30 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:29:19 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_merge(t_list **begin_list1, t_list *begin_list2)
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
