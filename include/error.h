/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:21:48 by knakto            #+#    #+#             */
/*   Updated: 2025/01/13 16:21:48 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	FREE,
	FREESPLIT,
	UNFREE
}	t_error;

void	show_error(char *text);
void	ft_error(char *text_exit, int exit_code, int free_code, void *content);
void	error_fail_check_in_store(char **arg, char *line, int fd);

#endif
