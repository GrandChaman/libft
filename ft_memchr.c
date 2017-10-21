/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:37:44 by bluff             #+#    #+#             */
/*   Updated: 2017/10/21 17:13:09 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void* ptr, int ch, size_t count)
{
	unsigned char c;
	unsigned int i;
	const unsigned char *buf;

	buf = ptr;
	i = 0;
	c = ch;
	while (i < count - 1 && *(buf + i) != c)
		i++;
	return (*(buf + i) == c ? (void*)buf + i : NULL);
}
