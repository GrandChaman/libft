/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:38:04 by bluff             #+#    #+#             */
/*   Updated: 2017/10/21 16:48:26 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;
	char c;

	c = ch;
	i = 0;
	while (str[i])
		if (str[i] == ch)
			return ((char*)str + i);
		else
			i++;
	if (str[i] == ch)
		return ((char*)str + i);
	else
		return (NULL);
}
