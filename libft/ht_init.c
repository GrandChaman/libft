/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:34:34 by fle-roy           #+#    #+#             */
/*   Updated: 2018/01/25 17:39:52 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ft_ht		ht_init(unsigned int size)
{
	t_ft_ht res;

	res.table = ft_memalloc(sizeof(t_ft_ht) * (size + 1));
	res.size = size;
	return (res);
}
