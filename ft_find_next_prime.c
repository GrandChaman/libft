/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 13:56:22 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:52:38 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	int prime;

	prime = 0;
	while (!prime)
		prime = ft_is_prime(nb++);
	return (--nb);
}