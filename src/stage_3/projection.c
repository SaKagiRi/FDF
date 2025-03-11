/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:46:44 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:22:54 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	rotation_z(float *x, float *y)
{
	float		temp_x;
	float		temp_y;
	float		radian;
	t_fdf		*fdf;

	fdf = get_t_fdf();
	radian = fdf->z_degree * PI / 180.0;
	temp_x = (cos(radian) * (*x)) - (sin(radian) * (*y));
	temp_y = (sin(radian) * (*x)) + (cos(radian) * (*y));
	*x = temp_x;
	*y = temp_y;
}

static void	rotation_y(float *x, float *z)
{
	float		temp_x;
	float		temp_z;
	float		radian;
	t_fdf		*fdf;

	fdf = get_t_fdf();
	radian = fdf->y_degree * PI / 180.0;
	temp_x = (cos(radian) * (*x)) + (sin(radian) * (*z));
	temp_z = (-sin(radian) * (*x)) + (cos(radian) * (*z));
	*x = temp_x;
	*z = temp_z;
}

static void	rotation_x(float *y, float *z)
{
	float		temp_y;
	float		temp_z;
	float		radian;
	t_fdf		*fdf;

	fdf = get_t_fdf();
	radian = fdf->x_degree * PI / 180.0;
	temp_y = (cos(radian) * (*y)) - (sin(radian) * (*z));
	temp_z = (sin(radian) * (*y)) + (cos(radian) * (*z));
	*y = temp_y;
	*z = temp_z;
}

void	setpoint(t_point *p, t_fdf *fdf)
{
	p->px = p->x * fdf->zoom;
	p->py = p->y * fdf->zoom;
	p->pz = p->z * fdf->zoom;
	rotation_z(&p->px, &p->py);
	rotation_y(&p->px, &p->pz);
	rotation_x(&p->py, &p->pz);
	p->px += fdf->px;
	p->py += fdf->py;
	if (fdf->line_color != 0xFFFFFF && p->color == 0xFFFFFF)
		p->color = fdf->line_color;
}
