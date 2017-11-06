/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:04:26 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:45:09 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*rev;
	t_list	*first;
	int		i;
	int		ii;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	i = 0;
	curr = *begin_list;
	while (curr->next && ++i)
		curr = curr->next;
	first = curr;
	ii = i;
	while (ii--)
	{
		rev = *begin_list;
		while (rev->next != curr)
			rev = rev->next;
		curr->next = rev;
		curr = rev;
	}
	curr->next = 0;
	*begin_list = first;
}
