/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 00:37:00 by bluff             #+#    #+#             */
/*   Updated: 2017/11/06 11:44:22 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	return (nb * ft_factorial(nb - 1));
}