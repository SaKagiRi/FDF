/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:19:23 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 21:55:55 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init(void)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	fdf->map_fd = 0;
	fdf->config_fd = 0;
	fdf->err = false;
	fdf->change = true;
	fdf->height = 0;
	fdf->width = 0;
	fdf->cache = NULL;
	fdf->bind = NULL;
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	fdf->texture = NULL;
	fdf->line_color = 0xFFFFFF;
}
