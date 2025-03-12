/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:20 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 07:07:23 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	point_set(void)
{
	int		i;
	int		j;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	i = 0;
	while (fdf->map[i])
	{
		j = 0;
		while (fdf->map[i][j])
		{
			setpoint(fdf->map[i][j], fdf);
			j++;
		}
		i++;
	}
	if (!fdf->disco)
		fdf->rot = 1;
	else
	{
		fdf->rot = 0;
		if (fdf->rot_color == 0)
			fdf->rot_color = 1;
	}
}

void	connect_point(t_fdf *fdf, int i, int j)
{
	i = 0;
	while (fdf->map[i + 1])
	{
		j = 0;
		while (fdf->map[i][j])
		{
			if (fdf->map[i][j + 1])
				bresenham(fdf, *fdf->map[i][j], *fdf->map[i][j + 1]);
			if (fdf->map[i + 1][j])
				bresenham(fdf, *fdf->map[i][j], *fdf->map[i + 1][j]);
			j++;
		}
		i++;
	}
	i = fdf->height - 1;
	j = fdf->width - 1;
	while (j >= 0)
	{
		if (fdf->map[i][j + 1])
			bresenham(fdf, *fdf->map[i][j], *fdf->map[i][j + 1]);
		j--;
	}
}

void	rev_connect_point(t_fdf *fdf, int i, int j)
{
	i = fdf->height - 2;
	while (i >= 0)
	{
		j = fdf->width - 1;
		while (j >= 0)
		{
			if (fdf->map[i][j + 1])
				bresenham(fdf, *fdf->map[i][j], *fdf->map[i][j + 1]);
			if (fdf->map[i + 1][j])
				bresenham(fdf, *fdf->map[i][j], *fdf->map[i + 1][j]);
			j--;
		}
		i--;
	}
	i = fdf->height - 1;
	j = fdf->width - 1;
	while (j >= 0)
	{
		if (fdf->map[i][j + 1])
			bresenham(fdf, *fdf->map[i][j], *fdf->map[i][j + 1]);
		j--;
	}
}

void	hook(void *param)
{
	t_fdf	*fdf;
	mlx_t	*mlx;

	mlx = param;
	fdf = get_t_fdf();
	if (!fdf->change)
		return ;
	cache(fdf);
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_texture_to_image(mlx, fdf->texture);
	mlx_image_to_window(mlx, fdf->img, 0, 0);
	fdf->change = false;
}

void	initmlx(void)
{
	t_list	*map;
	int		i;
	t_fdf	*fdf;
	int		j;
	int		k;

	fdf = get_t_fdf();
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	mlx_key_hook(fdf->mlx, control, fdf);
	mlx_loop_hook(fdf->mlx, hook, fdf->mlx);
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_terminate(fdf->mlx);
}
