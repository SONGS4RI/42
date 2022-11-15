/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:14:49 by jahlee            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/15 14:16:41 by jahlee           ###   ########.fr       */
=======
/*   Updated: 2022/11/14 16:57:10 by jahlee           ###   ########.fr       */
>>>>>>> 6e7b1a23e635c0c55fb44b5c375ff194cb28ec76
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
<<<<<<< HEAD
char	*ft_substr(char const *s, unsigned int start, size_t len);
=======
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
int     ft_atoi(const char *nptr);
void    *calloc(size_t nmemb, size_t size);

>>>>>>> 6e7b1a23e635c0c55fb44b5c375ff194cb28ec76
#endif