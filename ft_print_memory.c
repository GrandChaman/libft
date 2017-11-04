/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:17:24 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:48:39 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define CHARSET "0123456789abcdef"

static void to_hex(unsigned char nb)
{
	ft_putchar(CHARSET[nb % 16]);
	ft_putchar(CHARSET[(nb / 16) % 16]);
}

void	ft_print_memory(const void *addr, size_t size)
{
	unsigned char *buf;
	unsigned int i;
	unsigned int ii;
	int sp;

	sp = 0;
	ii = 0;
	i = 0;
	buf = (unsigned char*)addr;
	while (i < size)
	{
		ii = i;
		while (ii < 16 + i && ii < size)
		{
			to_hex(*(buf + ii++));
			if (sp > 0)
			{
				ft_putchar(' ');
				sp = 0;
				continue ;
			}
			sp++;
		}
		while (ii++ < 16 + i)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			if (sp)
			{
				ft_putchar(' ');
				sp = 0;
			}
			else
				sp++;
		}

		ii = i;
		while (ii < 15 + i && ii < size)
		{
			if (*(buf + ii) < 32 || *(buf + ii) > 126)
				ft_putchar('.');
			else
				ft_putchar(*(buf + ii));
			ii++;
		}
		ft_putchar('\n');
		i += 16;
	}
}
