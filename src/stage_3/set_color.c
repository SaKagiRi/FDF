/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:13:19 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 06:58:20 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int		get_rgba(long rgba, int sw)
{
	if (sw == 1)
		return ((rgba >> 24) & 0xFF);
	else if (sw == 2)
		return ((rgba >> 16) & 0xFF);
	else if (sw == 3)
		return ((rgba >> 8) & 0xFF);
	else if (sw == 4)
		return (rgba & 0xFF);
	return (0);
}

long	get_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

long	rot_color(long col, t_fdf *fdf)
{
	int	r;
	int	g;
	int	b;

	r = get_rgba(col, 1);
	g = get_rgba(col, 2);
	b = get_rgba(col, 3);
	if (fdf->rot_color == 0)
		return (col);
	else if (fdf->rot_color == 1)
		return (get_color(g, b, r, 0));
	else if (fdf->rot_color == 2)
		return (get_color(b, r, g, 0));
	else if (fdf->rot_color == 3)
		return (get_color(b, g, r, 0));
	else if (fdf->rot_color == 4)
		return (get_color(r, b, g, 0));
	return (col);
}

long	scolor(t_point pos, t_point *start, t_point *stop)
{
	int	num;

	num = 1;
	if (ft_abs(stop->py - start->py) < ft_abs(stop->px - start->px))
		num = 2;
	if (num == 1)
	{
		if (ft_abs(pos.px - start->px) < ft_abs(pos.px - stop->px))
			return (start->color);
		return (stop->color);
	}
	if (ft_abs(pos.py - start->py) < ft_abs(pos.py - stop->py))
		return (start->color);
	return (stop->color);
}
