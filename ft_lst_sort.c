/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:36:48 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:45:10 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	t_list	*first;
	void	*tmp;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	first = *begin_list;
	curr = first;
	while (curr && curr->next)
	{
		if ((*cmp)(curr->content, curr->next->content) > 0)
		{
			tmp = curr->next->content;
			curr->next->content = curr->content;
			curr->content = tmp;
			curr = *begin_list;
			continue ;
		}
		curr = curr->next;
	}
}
