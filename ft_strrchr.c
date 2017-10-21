/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:26:15 by bluff             #+#    #+#             */
/*   Updated: 2017/10/22 00:53:36 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;
	char c;

	c = ch;
	i = ft_strlen(str);
	while (i >= 0)
		if (str[i] == ch)
			return ((char*)str + i);
		else
			i--;
	return (NULL);
}
