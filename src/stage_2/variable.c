/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:59:32 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 02:18:35 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	set_value_variable(char *key, int nb)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (!ft_strncmp(key, "rotate", 6))
		fdf->rotate_size = nb;
	else if (!ft_strncmp(key, "move", 4))
		fdf->move_size = nb;
	else if (!ft_strncmp(key, "zoom", 4))
		fdf->zoom_size = nb;
	else if (!ft_strncmp(key, "start_x", 7))
		fdf->px = nb;
	else if (!ft_strncmp(key, "start_y", 7))
		fdf->py = nb;
	else if (!ft_strncmp(key, "color", 5))
		fdf->line_color = nb;
	else if (!ft_strncmp(key, "default", 7))
		fdf->set_default = 0;
}

void	config_color(char *key, char *col)
{
	long	color;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (ft_strncmp(col, "#", 1))
		return ;
	color = ft_htol(col + 1);
	if (!ft_strncmp(key, "color", 5))
		fdf->line_color = color;
	else
		fdf->bg_color = color;
}

void	variable(char *key, char *value)
{
	char	*str;
	int		nb;

	str = ft_strtrim(value, " \n");
	nb = ft_atoi(str);
	free(str);
	if (!ft_strncmp(key, "color", 5) || !ft_strncmp(key, "background", 10))
	{
		config_color(key, value);
		return ;
	}
	set_value_variable(key, nb);
}
