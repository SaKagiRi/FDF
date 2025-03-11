/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:20 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:43:08 by knakto           ###   ########.fr       */
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
}

void	connect_point(t_fdf *fdf, int i, int j)
{
	i = 0;
	while (fdf->map[i])
	{
		j = 0;
		while (fdf->map[i][j])
		{
			if (fdf->map[i][j + 1])
				bresenham(fdf, *fdf->map[i][j], *fdf->map[i][j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (fdf->map[i + 1])
	{
		j = 0;
		while (fdf->map[i][j])
		{
			bresenham(fdf, *fdf->map[i][j], *fdf->map[i + 1][j]);
			j++;
		}
		i++;
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
