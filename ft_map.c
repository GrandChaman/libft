/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 10:20:56 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/05 14:17:20 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ntab;
	int i;

	i = 0;
	if (!(ntab = (int*)malloc(sizeof(int) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		ntab[i] = f(tab[i]);
		i++;
	}
	return (ntab);
}
