/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:17:35 by bluff             #+#    #+#             */
/*   Updated: 2017/10/26 12:55:48 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;
	unsigned int i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}
