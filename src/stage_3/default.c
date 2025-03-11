/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:06:50 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 02:25:19 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	default_config(mlx_key_data_t d)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (!fdf->set_default)
		return ;
	if (d.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(fdf->mlx, fdf->img);
		mlx_terminate(fdf->mlx);
		clear(0);
	}
	else if (d.key == MLX_KEY_W)
		fdf->py += fdf->move_size;
	else if (d.key == MLX_KEY_S)
		fdf->py -= fdf->move_size;
	else if (d.key == MLX_KEY_A)
		fdf->px += fdf->move_size;
	else if (d.key == MLX_KEY_D)
		fdf->px -= fdf->move_size;
	fdf->change = 1;
}
