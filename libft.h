/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 20:24:12 by bluff             #+#    #+#             */
/*   Updated: 2017/10/31 18:14:04 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

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
char	*ft_strnstr(const char* str, const char* substr, size_t count);
int		ft_atoi(const char *str);
int		ft_isdigit(int ch);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(const char *s);
void	ft_putnbr(int n);
void 	ft_putendl(const char *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s);
t_list*		ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list*		ft_lstmap(t_list *lst, t_list* (*f)(t_list *elem));

#endif
