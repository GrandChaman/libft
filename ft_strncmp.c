/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:29:24 by bluff             #+#    #+#             */
/*   Updated: 2017/11/06 11:45:53 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	unsigned int i;

	i = 0;
	while (*lhs == *rhs && *lhs && *rhs && i < count)
	{
		lhs++;
		rhs++;
		i++;
	}
	return ((unsigned char)*lhs - (unsigned char)*rhs);
}
