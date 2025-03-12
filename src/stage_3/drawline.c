/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:40:43 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 05:44:13 by knakto           ###   ########.fr       */
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
	dx = stop->px - start->px;
	dy = stop->py - start->py;
	mirror(&dy, &inc);
	diff = (2 * dy) - dx;
	pos = *start;
	while (pos.px < stop-> px)
	{
		if (pos.px > 0 && pos.py > 0 && pos.px < WIDTH && pos.py < HEIGHT)
			ft_texture(fdf->texture, pos.px, pos.py, scolor(pos, start, stop));
		if (diff > 0)
		{
			pos.py += inc;
			diff += 2 * (dy - dx);
		}
		else
			diff += 2 * dy;
		pos.px++;
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
	dx = stop->px - start->px;
	dy = stop->py - start->py;
	mirror(&dx, &inc);
	diff = (2 * dx) - dy;
	pos = *start;
	while (pos.py < stop->py && pos.py < HEIGHT)
	{
		if (pos.px > 0 && pos.py > 0 && pos.px < WIDTH && pos.py < HEIGHT)
			ft_texture(fdf->texture, pos.px, pos.py, scolor(pos, start, stop));
		if (diff > 0)
		{
			pos.px += inc;
			diff += 2 * (dx - dy);
		}
		else
			diff += 2 * dx;
		pos.py++;
	}
}

static int	border_bound(t_point *ori, t_point *end)
{
	if (((ori->px < 0 && end->px < 0) || (ori->px > WIDTH && end->px > WIDTH)))
		return (0);
	if ((ori->py < 0 && end->py < 0) || (ori->py > HEIGHT && end->py > HEIGHT))
		return (0);
	return (1);
}

void	bresenham(t_fdf *fdf, t_point start, t_point stop)
{
	cohen(&start, &stop);
	if (!border_bound(&start, &stop))
		return ;
	if (ft_abs(stop.py - start.py) < ft_abs(stop.px - start.px))
	{
		if (start.px > stop.px)
			x_line(fdf, &stop, &start);
		else
			x_line(fdf, &start, &stop);
	}
	else
	{
		if (start.py > stop.py)
			y_line(fdf, &stop, &start);
		else
			y_line(fdf, &start, &stop);
	}
}
