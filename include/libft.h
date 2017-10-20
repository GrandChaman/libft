/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 20:24:12 by bluff             #+#    #+#             */
/*   Updated: 2017/10/20 19:05:51 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <string.h>

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *dest, int ch, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void* dest, const void* src, size_t count);
void	*ft_memchr(const void* ptr, int ch, size_t count);
int		ft_memcmp(const void* lhs, const void* rhs, size_t count);

#endif
