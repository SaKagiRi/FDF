/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:16:22 by knakto            #+#    #+#             */
/*   Updated: 2025/01/13 16:16:22 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	show_error(char *text)
{
	ft_putstr_fd(text, 2);
}

void	error_fail_check_in_store(char **arg, char *line, int fd)
{
	free_split(arg);
	free(line);
	close(fd);
}

void	ft_error(char *text_exit, int exit_code, int free_code, void *content)
{
	if (free_code == FREE)
		free(content);
	else if (free_code == FREESPLIT)
		free_split(content);
	show_error(text_exit);
	exit(exit_code);
}
