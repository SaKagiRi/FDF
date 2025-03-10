/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:40:43 by knakto            #+#    #+#             */
/*   Updated: 2025/03/10 19:48:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	mirror(int *diff, int *inc)
{
	if (*diff < 0)
	{
		*inc = -1;
		*diff = -*diff;
	}
}

static void	x_line(t_fdf *fdf, t_point *start, t_point *stop)
{
	int		dx;
	int		dy;
	int		inc;
	int		diff;
	t_point	pos;

	inc = 1;
	dx = stop->plot_x - start->plot_x;
	dy = stop->plot_y - start->plot_y;
	mirror(&dy, &inc);
	diff = (2 * dy) - dx;
	pos = *start;
	while (pos.plot_x < stop-> plot_x)
	{
		if (pos.plot_x > 0 && pos.plot_y > 0 && pos.plot_x < WIDTH && pos.plot_y < HEIGHT)
			draw_texture(fdf->texture, pos.plot_x, pos.plot_y, 0xFFFF);
		if (diff > 0)
		{
			pos.plot_y += inc;
			diff += 2 * (dy - dx);
		}
		else
			diff += 2 * dy;
		pos.plot_x++;
	}
}

static void	y_line(t_fdf *fdf, t_point *start, t_point *stop)
{
	int		dx;
	int		dy;
	int		inc;
	int		diff;
	t_point	pos;

	inc = 1;
	dx = stop->plot_x - start->plot_x;
	dy = stop->plot_y - start->plot_y;
	mirror(&dx, &inc);
	diff = (2 * dx) - dy;
	pos = *start;
	while (pos.plot_y < stop->plot_y && pos.plot_y < HEIGHT)
	{
		if (pos.plot_x > 0 && pos.plot_y > 0 && pos.plot_x < WIDTH && pos.plot_y < HEIGHT)
			draw_texture(fdf->texture, pos.plot_x, pos.plot_y, 0xFFFF);
		if (diff > 0)
		{
			pos.plot_x += inc;
			diff += 2 * (dx - dy);
		}
		else
			diff += 2 * dx;
		pos.plot_y++;
	}
}

static int	border_bound(t_point *ori, t_point *end)
{
	if (((ori->plot_x < 0 && end->plot_x < 0) || (ori->plot_x > WIDTH && end->plot_x > WIDTH)))
		return (0);
	if ((ori->plot_y < 0 && end->plot_y < 0) || (ori->plot_y > HEIGHT && end->plot_y > HEIGHT))
		return (0);
	return (1);
}

void	bresenham(t_point start, t_point stop)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	setpoint(&start, fdf);
	setpoint(&stop, fdf);
	if (!border_bound(&start, &stop))
		return ;
	if (abs((int)stop.plot_y - (int)start.plot_y) < abs((int)stop.plot_x - (int)start.plot_x))
	{
		if (start.plot_x > stop.plot_x)
			x_line(fdf, &stop, &start);
		else
			x_line(fdf, &start, &stop);
	}
	else
	{
		if (start.plot_y > stop.plot_y)
			y_line(fdf, &stop, &start);
		else
			y_line(fdf, &start, &stop);
	}
}
