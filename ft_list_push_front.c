/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:54:01 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:30:32 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;

	if (begin_list == NULL)
		return ;
	tmp = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = tmp;
		tmp->next = NULL;
		return ;
	}
	tmp->next = *begin_list;
	*begin_list = tmp;
}
