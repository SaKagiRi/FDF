/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kml.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:31:29 by knakto            #+#    #+#             */
/*   Updated: 2025/02/24 16:53:06 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KML_H
# define KML_H
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# include "get_next_line.h"

/*for lib*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	ft_find(char *str, char c);
size_t	count_word(char *s, char c);
void	ft_lstremove_if(t_list **list, void *data_ref,
			int (*cmp)(void *content, void *data_ref),
			void (*del)(void *content));
t_list	*ft_list_find(t_list *list, void *data_ref,
			int (*cmp)(void *content, void *data_ref));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter_if(t_list *list, void (*f)(void *), void *data_ref,
			int (*cmp)(void *contnet, void *data_ref));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

int		pnf(const char *str, ...);

char	*strjoin_nl(char *s1, char *s2);
char	*fjoin(char *s1, char *s2);
char	*argstr(char *find, char **n);
char	**free_split(char **alloc);
char	**fsplit(char *s, char c);

long	ft_atol(const char *nptr);
long	ft_htol(const char *nptr);

//env
//*   env_utils.c                         :+:      :+:    :+:   */
char	**envhead(void);
void	ft_envinit(void);
void	ft_unset(void);
void	ft_envput(void);
//*   env_function.c                      :+:      :+:    :+:   */
char	*find_env(char	*name);
char	*ft_envcreate(char *name, char *value);
void	ft_envadd(char *name, char *value);
void	ft_envupdate(char *name, char *value);
void	ft_envdelete(char	*name);
//*   env.c                               :+:      :+:    :+:   */
char	*ft_envget(char *name);
void	ft_export(char	*content);

#endif
