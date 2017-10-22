/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:47:51 by bluff             #+#    #+#             */
/*   Updated: 2017/10/22 18:02:35 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_isblank(char c)
{
	if (c == '\f' || c == '\t' || c == '\v' || c == '\n'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (sign * res);
}
