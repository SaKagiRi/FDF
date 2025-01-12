/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 02:31:35 by knakto            #+#    #+#             */
/*   Updated: 2025/01/12 02:31:35 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		pnf(const char *str, ...);
int		pnf_fd(int	fd, const char *str, ...);
void	ft_putnbr_fd(int n, int fd);

#endif
