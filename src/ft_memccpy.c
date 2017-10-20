/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:13:15 by bluff             #+#    #+#             */
/*   Updated: 2017/10/20 16:00:06 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char lc;

	lc = c;
	while (n-- && *((unsigned char*)src - 1) != lc)
		*((unsigned char*)dest++) = *((unsigned char*)src++);
	if (*((unsigned char*)src - 1) == lc)
		return (((unsigned char*)dest));
	else
		return (NULL);
}
