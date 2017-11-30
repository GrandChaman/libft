/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <allauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 03:21:03 by allauren          #+#    #+#             */
/*   Updated: 2017/11/30 13:41:18 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"
#include "ft_printf_format_list.h"
#include "libft/libft.h"

int								is_format_identifier(const char *str)
{
	int i;

	i = -1;
	while (g_format_list[++i].trigger)
		if (ft_strccmp(g_format_list[i].trigger, str))
			return (1);
	return (0);
}

int								is_arguments(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (FLAG_LIST[i])
		if (ft_strccmp(&FLAG_LIST[i++], str))
			res = 1;
	return (res);
}

void							ft_strtolower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
}

static void						ft_recursive(char *str, unsigned long long nb,
			unsigned long long base, unsigned long long i)
{
	if (i >= base)
	{
		if ((nb / i) < 10)
			*str = nb / i + '0';
		else
			*str = nb / i - 10 + 'A';
		ft_recursive((str + 1), (nb % i), base, (i / base));
		return ;
	}
	if (nb / i < 10)
		*str = nb / i + '0';
	else
		*str = nb / i - 10 + 'A';
}

char							*ft_itoa_base(unsigned long long nb, int base)
{
	unsigned long long	i;
	unsigned long long	t;
	char				*str;
	unsigned long long	count;
	unsigned long long	j;

	i = 1;
	count = 0;
	t = nb;
	j = 0;
	while ((t /= base))
		count++;
	count++;
	while (j++ < (count - 1))
		i = i * base;
	if (base < 2 || !(str = ft_strnew(count)))
		return (NULL);
	str[count] = '\0';
	if (nb == 0)
		str[0] = '0';
	else
		ft_recursive(str, nb, base, i);
	return (str);
}
