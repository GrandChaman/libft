/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 01:11:03 by bluff             #+#    #+#             */
/*   Updated: 2017/10/22 01:28:38 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *lhs, const char *rhs)
{
	while (*lhs == *rhs && *lhs && *rhs)
	{
		lhs++;
		rhs++;
	}
	return ((unsigned char)*lhs - (unsigned char)*rhs);
}
