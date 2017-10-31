/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:13:42 by bluff             #+#    #+#             */
/*   Updated: 2017/10/27 11:19:39 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (s[i])
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}