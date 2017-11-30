/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers_upper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:18:55 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/30 13:41:18 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include <stdarg.h>
#include "ft_printf_format_list.h"
#include "libft/libft.h"

int		print_octal_upper(t_ptf_toprint format, t_ptf_param param, va_list ap)
{
	param.lm = L;
	return (print_octal(format, param, ap));
}

int		print_unsigned_upper(t_ptf_toprint format, t_ptf_param param,
	va_list ap)
{
	param.lm = L;
	return (print_unsigned(format, param, ap));
}

int		print_signed_upper(t_ptf_toprint format, t_ptf_param param, va_list ap)
{
	param.lm = L;
	return (print_signed(format, param, ap));
}

int		hex_handler(int m, t_ptf_toprint format, t_ptf_param p, va_list ap)
{
	unsigned long long	n;
	int					res;
	int					len;
	char				*istr;

	res = 0;
	if (format.len)
		res += ft_putstr_limit(format.str, format.len);
	n = extract_nb(p, ap);
	istr = ft_itoa_base(n, 16);
	if (m == LOWER || m == POINTER)
		ft_strtolower(istr);
	len = ft_strlen(istr);
	p.padding -= (m == POINTER || (p.hashtag && (n || m == POINTER)) ? 2 : 0);
	if ((m == POINTER || (p.hashtag && n)) && p.zero)
		res += ft_putstr_limit((m == LOWER || m == POINTER ? "0x" : "0X"), 2);
	res += handle_padding(p, (n || p.precision ? len : -1), BEFORE);
	if ((m == POINTER || (p.hashtag && n)) && !p.zero)
		res += ft_putstr_limit((m == LOWER || m == POINTER ? "0x" : "0X"), 2);
	res += (p.precision > 0 ? print_padding('0', p.precision - len) : 0);
	if (n || p.precision)
		res += ft_putstr_limit(istr, len);
	res += handle_padding(p, (n || p.precision ? len : -1), AFTER);
	free(istr);
	return (res);
}

int		print_hex_upper(t_ptf_toprint format, t_ptf_param param, va_list ap)
{
	return (hex_handler(UPPER, format, param, ap));
}
