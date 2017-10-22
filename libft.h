/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 20:24:12 by bluff             #+#    #+#             */
/*   Updated: 2017/10/22 17:31:44 by bluff            ###   ########.fr       */
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
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t count);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t count);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strstr(const char* str, const char* substr);
int		ft_strcmp(const char *lhs, const char *rhs);
int		ft_strncmp(const char *lhs, const char *rhs, size_t count);

#endif
