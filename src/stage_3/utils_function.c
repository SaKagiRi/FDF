/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:30:55 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:35:28 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	set_view(int view)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (view == ISO)
	{
		// fdf->x_degree = 45;
		fdf->x_degree = 55;
		// fdf->z_degree = 35.264;
		fdf->z_degree = 44.6999;
		fdf->y_degree = 0;
	}
	else if (view == BIRDVIEW)
	{
		fdf->x_degree = 0;
		fdf->z_degree = 0;
		fdf->y_degree = 0;
	}
}

void	ft_zoom(t_fdf *fdf, int sw)
{
	if (sw == 1 && fdf->zoom < 200)
		fdf->zoom += fdf->zoom_size;
	else if (sw == 2 && fdf->zoom > 2)
		fdf->zoom -= fdf->zoom_size;
	if (fdf->zoom <= 0)
		fdf->zoom = 1;
}

void	ft_rotate(t_fdf *fdf, int sw)
{
	float	*nb;

	if (sw == 1 || sw == 2)
		nb = &fdf->x_degree;
	if (sw == 3 || sw == 4)
		nb = &fdf->y_degree;
	if (sw == 5 || sw == 6)
		nb = &fdf->z_degree;
	if (sw % 2 != 0)
	{
		*nb += fdf->rotate_size;
		if (*nb >= 360)
			*nb = 1;
	}
	else
	{
		*nb -= fdf->rotate_size;
		if (*nb <= 0)
			*nb = 360;
	}
}

void	ft_exit(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_terminate(fdf->mlx);
	clear(0);
}
