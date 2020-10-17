/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:05:01 by nlee              #+#    #+#             */
/*   Updated: 2020/10/15 13:29:18 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *src, size_t n);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memccpy(void *dst, const void *src, int c, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t n);
void    *ft_memchr(const void *src, int c, size_t n);
int     ft_memcmp(const void *src1, const void *src2, size_t n);
size_t  ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
char    *ft_strchr(const char *str, int c);
char    *ft_strrchr(const char *str, int c);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int     ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);

size_t  ft_countchr(const char *str, int c);
int		ft_isspace(int c);
#endif
