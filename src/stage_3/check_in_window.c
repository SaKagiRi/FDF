/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:21:14 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 05:43:57 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	change_point(t_point *p, float dy, float dx, float m)
{
	if (p->outcode & 0b1000)
		p->px = p->px + ((0 - p->py) / m);
	if (p->outcode & 0b0100)
		p->px = p->px + ((HEIGHT - p->py) / m);
	if (p->outcode & 0b0010)
		p->py = p->py + (m * (WIDTH - p->px));
	if (p->outcode & 0b0001)
		p->py = p->py + (m * (0 - p->px));
}

void	cohen(t_point *s1, t_point *s2)
{
	float		dx;
	float		dy;
	float		m;

	if ((s1->outcode & s2->outcode) == 0)
		return ;
	dx = s2->px - s1->px;
	dy = s2->py - s1->py;
	m = dy / dx;
	change_point(s1, dy, dx, m);
	change_point(s2, dy, dx, m);
}
