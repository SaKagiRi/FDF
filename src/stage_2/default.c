/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:35:31 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:22:27 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	set_default(void)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	fdf->zoom = 1;
	fdf->line_color = 0xFF;
	fdf->bg_color = 0x0;
	fdf->px = (float)WIDTH / 2;
	fdf->py = (float)HEIGHT / 1.5;
	fdf->x_degree = 45;
	fdf->z_degree = 35.264;
	fdf->y_degree = 0;
	fdf->rotate_size = 1;
	fdf->move_size = 1;
	fdf->zoom_size = 1;
	fdf->line_color = 0xFFFFFF;
}
