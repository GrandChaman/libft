/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
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
#include "libft.h"

int		print_signed(t_ptf_toprint format, t_ptf_param p, va_list ap)
{
	unsigned long long	n;
	int					res;
	int					len;

	res = 0;
	if (format.len)
		res += ft_putstr_limit(format.str, format.len);
	n = extract_nb_signed(&p, ap);
	len = ft_nblen(n) + (!n ? 1 : 0);
	p.padding += (!p.precision && !n ? 1 : 0);
	p.padding -= (((p.plus || (p.space && (len < p.padding
					|| p.padding <= 0))) && !p.neg) ? 1 : 0);
	if (p.space)
		res += print_padding((p.neg ? '-' : ' '), 1);
	if ((p.plus || p.neg) && p.zero && !p.space)
		res += print_padding((p.neg ? '-' : '+'), 1);
	res += handle_padding(p, len, BEFORE);
	if ((p.plus || p.neg) && !p.zero && !p.space)
		res += print_padding((p.neg ? '-' : '+'), 1);
	if (p.precision > 0)
		res += print_padding('0', p.precision - len);
	if (!(!p.precision && !n))
		ft_putll(n, &res);
	res += handle_padding(p, len, AFTER);
	return (res);
}

int		print_unsigned(t_ptf_toprint format, t_ptf_param param, va_list ap)
{
	unsigned long long	n;
	int					res;
	int					len;

	res = 0;
	if (format.len)
		res += ft_putstr_limit(format.str, format.len);
	n = extract_nb(param, ap);
	len = ft_nblen(n);
	len = (n ? len : 1);
	res += handle_padding(param, len, BEFORE);
	if (param.hashtag)
		res += print_padding('0', 1);
	if (param.precision > 0)
		res += print_padding('0', param.precision - len);
	if (param.precision || n)
		ft_putll(n, &res);
	res += handle_padding(param, len, AFTER);
	return (res);
}

int		print_octal(t_ptf_toprint format, t_ptf_param param, va_list ap)
{
	unsigned long long	n;
	int					res;
	int					len;
	char				*istr;

	res = 0;
	if (format.len)
		res += ft_putstr_limit(format.str, format.len);
	n = extract_nb(param, ap);
	istr = ft_itoa_base(n, 8);
	len = ft_strlen(istr);
	param.padding += (!param.precision && !n ? 1 : 0);
	if (param.precision > 0)
		param.hashtag = 0;
	param.padding -= (param.hashtag && n ? 1 : 0);
	res += handle_padding(param, len, BEFORE);
	if (param.hashtag && (n || !param.precision))
		res += print_padding('0', 1);
	if (param.precision > 0)
		res += print_padding('0', param.precision - len);
	if (n || param.precision)
		res += ft_putstr_limit(istr, len);
	res += handle_padding(param, len, AFTER);
	free(istr);
	return (res);
}

int		print_hex(t_ptf_toprint format, t_ptf_param param, va_list ap)
{
	return (hex_handler(LOWER, format, param, ap));
}

int		print_pointer(t_ptf_toprint format, t_ptf_param param, va_list ap)
{
	param.hashtag = 1;
	param.lm = L;
	return (hex_handler(POINTER, format, param, ap));
}
