/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:13:56 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/24 19:33:30 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# define BUFFER_SIZE 5000
# define OPEN_MAX 32

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
unsigned long long	ft_atoy(const char *str);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_isdigit(int c);
int					ft_tolower(int c);
char				ft_isalnum(char c);
int					ft_isascii(int c);
char				*ft_strchr(const char *s, int c);
int					ft_isprint(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(const char *s);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_atoi(const char *str);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src,
						size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src,
						size_t dstsize);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, int start, int len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_strcmp(char *s1, char *s2);

#endif