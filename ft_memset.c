/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 19:15:43 by bluff             #+#    #+#             */
/*   Updated: 2017/10/19 23:30:13 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	unsigned int i;
	unsigned char c;
	void *bckup;

	bckup = dest;
	i = 0;
	c = ch;
	while (i++ < count)
		*(char*)(dest++) = c;
	return (bckup);
}
