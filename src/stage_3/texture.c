/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:05:45 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:39:07 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_texture(mlx_texture_t *texture, float x, float y, size_t rgb)
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
	int		y;
	int		x;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	y = 0;
	while (y < texture->height)
	{
		x = 0;
		while (x < texture->width)
		{
			ft_texture(texture, x, y, fdf->bg_color);
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
