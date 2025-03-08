/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:36:43 by knakto            #+#    #+#             */
/*   Updated: 2025/03/07 06:29:59 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rotation_y(float *x, float *z)
{
	float	temp_x;
	float	temp_z;
	float	radian;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	radian = fdf->y_degree * PI / 180.0;
	temp_x = (cos(radian) * (*x)) - (sin(radian) * (*z));
	temp_z = (sin(radian) * (*x)) + (cos(radian) * (*z));
	*x = temp_x;
	*z = temp_z;
}

static void	rotation_z(float *x, float *y)
{
	float	temp_x;
	float	temp_y;
	float	radian;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	radian = fdf->z_degree * PI / 180.0;
	temp_x = (cos(radian) * (*x)) + (sin(radian) * (*y));
	temp_y = (-sin(radian) * (*x)) + (cos(radian) * (*y));
	*x = temp_x;
	*y = temp_y;
}

static void	rotation_x(float *z, float *y)
{
	float	temp_z;
	float	temp_y;
	float	radian;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	radian = fdf->x_degree * PI / 180.0;
	temp_z = (cos(radian) * (*z)) - (sin(radian) * (*y));
	temp_y = (sin(radian) * (*z)) + (cos(radian) * (*y));
	*z = temp_z;
	*y = temp_y;
}

t_point	*projection2d(t_point *point)
{
	t_point	*p;
	t_fdf	*fdf;
	float	x;
	float	z;
	float	y;

	fdf = get_t_fdf();
	x = point->x;
	y = point->y;
	z = point->z;
	p = malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	x += fdf->px;
	z += fdf->py;
	rotation_y(&x, &z);
	rotation_x(&z, &y);
	rotation_z(&x, &y);
	p->x = x * fdf->zoom + ((float)fdf->width / 2);
	p->z = z * fdf->zoom + ((float)fdf->height / 2);
	p->color = 0xFF;
	if (point->color)
		p->color = point->color;
	return (p);
}
