/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:20 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 16:57:55 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	point_set(void)
{
	int	i;
	int	j;
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

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	static mlx_key_data_t modifier;

	fdf = get_t_fdf();
	// if (keydata.key != (MLX_KEY_Z && MLX_KEY_X && MLX_KEY_W && MLX_KEY_A && MLX_KEY_S && MLX_KEY_D))
	// 	return ;
	if (keydata.modifier == 0)
		modifier = keydata;
	
	if ((modifier.key == MLX_KEY_LEFT_CONTROL && modifier.action == 1) && (keydata.action == 1 && keydata.key == MLX_KEY_D) && keydata.modifier == 2)
		pnf("success\n\n\n");
	if (keydata.key == MLX_KEY_Z && fdf->zoom < 100)
		fdf->zoom += 4;
	if (keydata.key == MLX_KEY_X && fdf->zoom > 20)
		fdf->zoom -= 4;
	if (keydata.key == MLX_KEY_W)
		fdf->py += 2;
	if (keydata.key == MLX_KEY_S)
		fdf->py -= 2;
	if (keydata.key == MLX_KEY_A)
		fdf->px += 2;
	if (keydata.key == MLX_KEY_D)
		fdf->px -= 2;
	if (keydata.key == MLX_KEY_Q)
	{
		if (keydata.action == 2)
			fdf->z_degree -= 1;
		else
			fdf->z_degree -= 0.5;
	}
	if (keydata.key == MLX_KEY_E)
	{
		if (keydata.action == 2)
			fdf->z_degree += 1;
		else
			fdf->z_degree += 0.5;
	}
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(fdf->mlx, fdf->img);
		// mlx_delete_texture(fdf->texture);
		mlx_terminate(fdf->mlx);
		clear(3);
	}
	fdf->change = true;
}

void	connect_point(void)
{
	t_fdf	*fdf;
	int		i;
	int		j;

	fdf = get_t_fdf();
	i = 0;
	while (fdf->map[i])
	{
		j = 0;
		while (fdf->map[i][j])
		{
			if (fdf->map[i][j + 1])
				bresenham(fdf, *fdf->map[i][j], *fdf->map[i][j + 1]);
			// if (fdf->map[i + 1][j])
			// 	bresenham(fdf, *fdf->map[i][j], *fdf->map[i + 1][j]);
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
	mlx_delete_image(fdf->mlx, fdf->img);
	cache(fdf);
	// mlx_delete_texture(fdf->texture);
	// fdf->texture = new_texture(WIDTH, HEIGHT);
	// testbresenham();
	// point_set();
	// fill_background(fdf->texture);
	// connect_point();
	fdf->img = mlx_texture_to_image(mlx, fdf->texture);
	mlx_image_to_window(mlx, fdf->img, 0, 0);
	fdf->change = false;
	// mlx_delete_image(mlx, fdf->img);
}

void	initmlx(void)
{
		t_list *map;
	int		i;
	t_fdf	*fdf;
	int		j;
	int		k;

	fdf = get_t_fdf();
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	// img = mlx_new_image(mlx, 256, 256);
	// printf("%d, %d\n", texture->width, texture->height);	
	fdf->texture = new_texture(WIDTH, HEIGHT);
	
	// i = 0;
	// fdf->change = true;
	// while (map->next)
	// {
	// 	bresenham(map->content, map->next->content);
	// 	map = map->next;
	// }
		// draw_texture(fdf->texture, (float)i, (float)i, 0xFF);
	
	// zoom();
	// fdf->change = 1;
	fdf->zoom = 1;
	fdf->px = (float)WIDTH / 2;
	fdf->py = (float)HEIGHT / 1.5;
	// i = 0;
	// j = 500;
	// while (i++ < 500 && j-- > 0)
	// {
	// }


	// connect_point();
	// // testbresenham();
	// fdf->img = mlx_texture_to_image(fdf->mlx, fdf->texture);
	// mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	

	mlx_key_hook(fdf->mlx, keyhook, NULL);
	mlx_loop_hook(fdf->mlx, hook, fdf->mlx);
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img);
	// mlx_delete_texture(fdf->texture);
	mlx_terminate(fdf->mlx);
}
