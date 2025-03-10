/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endstage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:16:18 by knakto            #+#    #+#             */
/*   Updated: 2025/03/10 19:26:04 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	set_point(void)
{
	t_fdf	*fdf;
	t_point	***map;
	int		i;
	int		j;

	fdf = get_t_fdf();
	map = fdf->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->x = j - fdf->width / 2;
			map[i][j]->y = i - fdf->height / 2;
			j++;
		}
		i++;
	}
}

void	endstage_1(void)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	set_point();
	ft_lstclear(&(fdf->all_map), free);
	close(fdf->map_fd);
}
