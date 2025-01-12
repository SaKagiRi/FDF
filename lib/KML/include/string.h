/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 02:29:30 by knakto            #+#    #+#             */
/*   Updated: 2025/01/12 02:29:30 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include<stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(const char *s, char c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*strjoin_nl(char *s1, char *s2);
char	*fjoin(char *s1, char *s2);
char	*argstr(char *find, char **n);
char	**free_split(char **alloc);
char	**fsplit(char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
