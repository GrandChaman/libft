/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 00:27:09 by bluff             #+#    #+#             */
/*   Updated: 2017/10/21 01:15:23 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t count)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < count)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < count)
		dest[i++] = '\0';
	return (dest);
}
