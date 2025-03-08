/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:42:53 by knakto            #+#    #+#             */
/*   Updated: 2025/03/07 06:52:19 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_x(t_draw  *all)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	all->diff =	(2 * all->dy) - all->dx;
	all->rx = all->x1;
	all->rz = all->z1;
	while (all->rx < all->x2)
	{
		if (all->rx > 0 && all->rz > 0 && all->rx < WIDTH && all->rz < HEIGHT)
			draw_texture(fdf->texture, all->rx, all->rz, all->col1);
		if (all->diff > 0)
		{
			all->rz += all->inc;
			all->diff += 2 * (all->dy - all->dx);
		}
		else
			all->diff += 2 * all->dy;
		all->rx++;
	}
}

void	draw_z(t_draw *all)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	all->diff = (2 * all->dx) - all->dy;
	all->rx = all->x1;
	all->rz = all->z1;
	while (all->rz < all->z2 && all->rz < WIDTH)
	{
		if (all->rx > 0 && all->rz > 0 && all->rx < WIDTH && all->rz < HEIGHT)
			draw_texture(fdf->texture, all->rx, all->rz, all->col1);
		if (all->diff > 0)
		{
			all->rx += all->inc;
			all->diff += 2 * (all->dx - all->dy);
		}
		else
			all->diff += 2 * all->dx;
		all->rz++;
	}
}

float	ft_abs(float f1)
{
	if (f1 < 0)
		return (f1 *= -1);
	return (f1);
}

void	store_draw(t_draw *all, t_point *s1, t_point *s2)
{
	all->x1 = s1->x;
	all->z1 = s1->z;
	all->col1 = s1->color;
	all->x2 = s2->x;
	all->z2 = s2->z;
	all->col1 = s2->color;
	all->inc = 1;
	all->dx = all->x2 - all->x1;
	all->dy = all->z2 - all->z1;
	if (all->dx < 0 || all->dy < 0)
		all->inc = -1;
	if (ft_abs(all->dy) > ft_abs(all->dx))
	{
		if (all->z1 > all->z2)
			store_draw(all, s2, s1);
		if (all->dx < 0)
			all->dx	 *= -1;
		all->axis = 'z';
		return ;
	}
	else
		if (all->dy < 0)
			all->dy	 *= -1;
}

void	bresenham(t_point *start, t_point *stop)
{
	t_draw	draw;
	
	if (start->x == stop->x && start->y == stop->y && start->z == stop->z)
		return ;
	if (start->x > stop->x)
		store_draw(&draw, stop, start);
	else
		store_draw(&draw, start, stop);
	if (draw.axis != 'z')
		draw_x(&draw);
	else
		draw_z(&draw);
	free(start);
	free(stop);
}
