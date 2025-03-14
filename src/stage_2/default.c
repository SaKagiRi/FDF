/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:35:31 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 07:06:07 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	set_default(void)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	fdf->zoom = 20;
	fdf->line_color = 0xFF;
	fdf->bg_color = 0x0;
	fdf->px = (float)WIDTH / 2;
	fdf->py = (float)HEIGHT / 1.5;
	fdf->x_degree = 55;
	fdf->z_degree = 44.6999;
	fdf->y_degree = 0;
	fdf->rotate_size = 1;
	fdf->move_size = 1;
	fdf->zoom_size = 1;
	fdf->line_color = 0xFFFFFF;
	fdf->set_default = 1;
	fdf->rot_color = 0;
	fdf->rot = 0;
	fdf->disco = 0;
}
