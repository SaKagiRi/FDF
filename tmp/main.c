/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:03:40 by knakto            #+#    #+#             */
/*   Updated: 2025/03/07 07:14:44 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>
#include <threads.h>

void	ft_clear(int status)
{
	t_list	*map;
	t_fdf	*fdf;

	ft_unset();
	ft_lstclear(getmap(), free);
	fdf = get_t_fdf();
	free(fdf->headline);
	free(fdf->endline);
	if (status == 1)
		ft_putstr_fd("Error\n", 2);
	exit(status);
}

void	print_line_pointer()
{
	t_fdf	*fdf;
	char	*getheight;	
	int		height;
	t_list	*node;
	t_list	*node2;
	int		i;

	fdf = get_t_fdf();
	i = 0;
	getheight = ft_envget("height");
	height = ft_atoi(getheight);
	free(getheight);
	while (i < height)
	{
		node = fdf->headline[i];
		printf("fdf->headline_z[%d] = %f\n", i, (float)((t_point *)node->content)->z);
		printf("fdf->headline_x[%d] = %f\n", i, (float)((t_point *)node->content)->x);
		node2 = fdf->endline[i];
		printf("fdf->endline_z[%d] = %f\n", i, (float)((t_point *)node2->content)->z);
		printf("fdf->endline_x[%d] = %f\n\n", i, (float)((t_point *)node2->content)->x);
		i++;
	}
	pnf("->>>%d\n", fdf->color);
}

void	test_mlx(void);
int	main(int c, char **v, char **env)
{
	t_list	*map;
	t_fdf	*fdf;

	if (c != 2)
		return (0);
	init(v[1], env);
	if (!check_file_name() || !get_width_height())
		ft_clear(1);
	get_profile();
	readmap();
	if (!store_line_pointer())
		ft_clear(1);
	print_line_pointer();
	ft_envput();
	test_mlx();
	ft_clear(0);
}

int	draw_texture(mlx_texture_t *texture, float x, float y, size_t rgb)
{
	size_t	position;

	if (x < 0 || y < 0)
		return (0);
	if (x >= texture->width || y >= texture->height)
		return (0);
	position = ((int32_t)y * texture->width * 4) + ((int32_t)x * 4);
	texture->pixels[position] = rgb >> 16 & 0xFF;
	texture->pixels[position + 1] = rgb >> 8 & 0xFF;
	texture->pixels[position + 2] = rgb & 0xFF;
	texture->pixels[position + 3] = 0xFF;
	return (1);
}

void	fill_background(mlx_texture_t *texture)
{
	int	y;
	int	x;

	y = 0;
	while (y < texture->height)
	{
		x = 0;
		while (x < texture->width)
		{
			draw_texture(texture, x, y, 0xFFF);
			x++;
		}
		y++;
	}
}

mlx_texture_t	*new_texture(size_t w, size_t h)
{
	mlx_texture_t	*texture;
	uint8_t			*pixels;

	texture = malloc(sizeof(mlx_texture_t));
	pixels = malloc(sizeof(uint8_t) * w * h * 4);
	if (!texture || !pixels)
		return (NULL);
	texture->width = w;
	texture->height = h;
	texture->bytes_per_pixel = 4;
	texture->pixels = pixels;
	fill_background(texture);
	return (texture);
}

void	connect_point(void)
{
	t_list	*p_start;
	t_list	*p_parallel;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	p_start = fdf->map;
	p_parallel = fdf->headline[1];
	while (p_start->next)
	{
		pnf("->>%d\n", ((t_point *)p_start->content)->x);
		if (!((t_point *)p_start->content)->last)
			bresenham(projection2d(p_start->next->content), projection2d(p_start->content));
		if (p_parallel)
		{
			bresenham(projection2d(p_parallel->content), projection2d(p_start->content));
			p_parallel = p_parallel->next;
		}
		p_start = p_start->next;
	}
}

void	testbresenham(void)
{
	t_point	*a;
	t_point	*b;
	int	i;
	int	j;

	a = malloc(sizeof(t_point));
	b = malloc(sizeof(t_point));
	i = 0;
	j = 500;
	while (i < j)
	{
		a->x = 0;
		a->z = i;
		b->x = i;
		b->z = 0;
		bresenham(b, a);
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
	mlx_delete_texture(fdf->texture);
	fdf->texture = new_texture(WIDTH, HEIGHT);
	connect_point();
	// testbresenham();
	fdf->img = mlx_texture_to_image(mlx, fdf->texture);
	mlx_image_to_window(mlx, fdf->img, 0, 0);
	fdf->change = 0;
	// mlx_delete_image(mlx, fdf->img);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	// if (keydata.key != (MLX_KEY_Z && MLX_KEY_X && MLX_KEY_W && MLX_KEY_A && MLX_KEY_S && MLX_KEY_D))
	// 	return ;
	if (keydata.key == MLX_KEY_Z && fdf->zoom < 100)
		fdf->zoom += 2;
	if (keydata.key == MLX_KEY_X && fdf->zoom > 0.2)
		fdf->zoom -= 2;
	if (keydata.key == MLX_KEY_W)
		fdf->py += 2;
	if (keydata.key == MLX_KEY_S)
		fdf->py -= 2;
	if (keydata.key == MLX_KEY_A)
		fdf->px += 2;
	if (keydata.key == MLX_KEY_D)
		fdf->px -= 2;
	if (keydata.key == MLX_KEY_Q)
		fdf->z_degree -= 2;
	if (keydata.key == MLX_KEY_E)
		fdf->z_degree += 2;
	fdf->change = 1;
}

void	test_mlx(void)
{
	t_list *map;
	int		i;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	map = *getmap();
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	// img = mlx_new_image(mlx, 256, 256);
	// printf("%d, %d\n", texture->width, texture->height);	
	fdf->texture = new_texture(WIDTH, HEIGHT);
	
	// i = 0;
	// while (map->next)
	// {
	// 	bresenham(map->content, map->next->content);
	// 	map = map->next;
	// }
		// draw_texture(fdf->texture, (float)i, (float)i, 0xFF);
	
	// zoom();
	fdf->change = 1;
	fdf->zoom = 50;
	// connect_point();
	// // testbresenham();
	// fdf->img = mlx_texture_to_image(fdf->mlx, fdf->texture);
	// mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	// mlx_delete_image(fdf->mlx, fdf->img);
	
	mlx_key_hook(fdf->mlx, keyhook, NULL);
	mlx_loop_hook(fdf->mlx, hook, fdf->mlx);
	mlx_loop(fdf->mlx);
	mlx_delete_texture(fdf->texture);
	mlx_terminate(fdf->mlx);
}
