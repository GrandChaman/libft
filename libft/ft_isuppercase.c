/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:22:35 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/07 14:26:17 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isuppercase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= 'A' && str[i] <= 'Z') && ft_isalpha(str[i]))
			return (0);
	return (1);
}