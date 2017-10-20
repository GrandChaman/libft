/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:05:06 by bluff             #+#    #+#             */
/*   Updated: 2017/10/20 19:40:45 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int		ft_memcmp(const void* lhs, const void* rhs, size_t count)
{
	unsigned int		i;
	const unsigned char	*fbuf;
	const unsigned char	*sbuf;

	i = 0;
	fbuf = lhs;
	sbuf = rhs;
	while (*(fbuf + i) == *(sbuf + i) && i < count)
		i++;
	return ((i == count) ? 0 : *(fbuf + i) - *(sbuf + i));
}
