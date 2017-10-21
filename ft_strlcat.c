/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:56:06 by bluff             #+#    #+#             */
/*   Updated: 2017/10/21 13:55:50 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int ii;
	unsigned int res;

	i = ft_strlen(dst);
	res = i;
	ii = 0;
	while (src[ii] && i + ii < size - 1)
	{
		dst[i + ii] = src[ii];
		ii++;
	}
	dst[i + ii + 1] = '\0';
	return (i + ft_strlen(src));
}
