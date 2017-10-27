/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:21:21 by bluff             #+#    #+#             */
/*   Updated: 2017/10/27 11:55:30 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int i;
	int ii;
	int len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	ii = len - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[ii] == ' ' || s[ii] == '\n' || s[ii] == '\t')
		ii--;
	if (((ii + 1) - i) < 0)
		return (ft_strsub(s, i, 0));
	return (ft_strsub(s, i, (ii + 1) - i));
}
