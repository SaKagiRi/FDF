/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:19:23 by knakto            #+#    #+#             */
/*   Updated: 2025/03/10 05:29:09 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init(void)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	fdf->map_fd = 0;
	fdf->config_fd = 0;
	fdf->mouse = false;
	fdf->err = false;
	fdf->color = false;
	fdf->change = true;
	fdf->height = 0;
	fdf->width = 0;
	fdf->px = 0;
	fdf->py = 0;
	fdf->zoom = 1;
	fdf->x_degree = 45;
	fdf->z_degree = 35.264;
	fdf->y_degree = 0;
	fdf->bind = NULL;
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	fdf->texture = NULL;
}
