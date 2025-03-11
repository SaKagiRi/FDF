/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:13:19 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:40:54 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
