/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:58:59 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:45:10 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lst_size(t_list *begin_list)
{
	int c;

	if (begin_list == NULL)
		return (0);
	c = 1;
	while ((begin_list = begin_list->next))
		c++;
	return (c);
}
