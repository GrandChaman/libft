/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 12:23:57 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:45:58 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		s;
	char	tmp[ft_strlen(str)];

	s = ft_strlen(str);
	i = -1;
	while (++i < s)
		tmp[(s - 1) - i] = str[i];
	i = -1;
	while (++i < s)
		str[i] = tmp[i];
	return (str);
}
