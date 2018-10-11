/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 23:36:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 15:27:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s, const char *t);
char			*ft_strnstr(const char *s, const char *t, size_t len);
int				ft_strcmp(const char *s, const char *t);
int				ft_strncmp(const char *s, const char *t, size_t len);
int				ft_atoi(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **mem);
char			*ft_strnew(size_t len);
void			ft_strdel(char **s);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char *s, char (*f)(char));
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t size);
void			ft_lstdelone(t_list **lp, void(*del)(void*, size_t));
void			ft_lstdel(t_list **lp, void (*del)(void*, size_t));
void			ft_lstadd(t_list **lp, t_list *new);
void			ft_lstiter(t_list *l, void(*f)(t_list *elem));
t_list			*ft_lstmap(t_list *l, t_list*(*f)(t_list *elem));

char			*ft_strcjoin(const char *s, char c, const char *t);
char			*ft_strvjoin(const char **strv, const char *sep);

typedef struct	s_btree
{
	void			*data;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;
t_btree			*ft_btree_new(void *data);
void			ft_btree_add(t_btree **root, void *ctx, void *data,
	int (*cmp)(void *ctx, void*, void*));
void			ft_btree_del(t_btree **tree, void *ctx,
	void (*del)(void *ctx, void*));
void			*ft_btree_find(t_btree *tree, void *key, void *ctx,
	int (*cmp)(void *ref, void*, void*));
void			ft_btree_preorder(t_btree *tree, void *ctx,
	void (*f)(void *ref, void*));
void			ft_btree_inorder(t_btree *tree, void *ctx,
	void (*f)(void *ctx, void*));
void			ft_btree_postorder(t_btree *tree, void *ctx,
	void (*f)(void *ctx, void*));
void			ft_btree_backpreorder(t_btree *tree, void *ctx,
	void (*f)(void*, void*));
void			ft_btree_backinorder(t_btree *tree, void *ctx,
	void (*f)(void*, void*));
void			ft_btree_backpostorder(t_btree *tree, void *ctx,
	void (*f)(void*, void*));
/*
** char *ft_strsjoin(const char *s, char* sep, const char *t);
** char	*ft_strchrs(const char *s, const char *targets);
** void	*ft_strreduce(char *s, char (*f)(void *acc, char));
** void	*ft_strreducei(char *s, char (*f)(void *acc, unsigned int, char));
** void	ft_lstsort(t_list *lst, void* ref, int (*f)(void*, void*, void*));
** void	ft_lstbubblesort(t_list *lst, void* ref, int (*f)(void*, void*, void*);
** void	ft_lstmergesort(t_list *lst, void* ref, int (*f)(void*, void*, void*);
** void	ft_lstquicksort(t_list *lst, void* ref, int (*f)(void*, void*, void*);
*/

#endif
