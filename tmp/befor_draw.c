/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   befor_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:17:46 by knakto            #+#    #+#             */
/*   Updated: 2025/03/07 06:29:54 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	setting_fdf(void)
{
	t_fdf	*fdf;
	char	*temp;

	fdf = get_t_fdf();
	temp = ft_envget("width");
	if (!temp)
		return (0);
	fdf->width = ft_atoi(temp);
	free(temp);
	temp = ft_envget("height");
	if (!temp)
		return (0);
	fdf->height = ft_atoi(temp);
	free(temp);
	fdf->endline = malloc(sizeof(void *) * fdf->height);
	fdf->headline = malloc(sizeof(void *) * fdf->height);
	if (!fdf->endline || !fdf->headline)
		return (0);
	fdf->map = *getmap();
	fdf->x_degree = 45;
	fdf->z_degree = 0;
	fdf->y_degree = 35.264;
	fdf->px = (float)fdf->width / 2;
	fdf->py = (float)fdf->height / 2;
	return (1);
}

int	store_line_pointer(void)
{
	t_list	*map;
	t_fdf	*fdf;
	int		i;
	int		j;

	if (!setting_fdf())
		return (0);
	i = 0;
	j = 0;
	map = *getmap();
	fdf = get_t_fdf();
	while (map)
	{
		((t_point *)map->content)->last = 0;
		if (((t_point *)map->content)->x == 1)
			fdf->headline[i++] = (void *)map;
		if (((t_point *)map->content)->x == fdf->width)
		{
			fdf->endline[j++] = (void *)map;
			((t_point *)map->content)->last = 1;
		}
		map = map->next;
	}
	return (1);
}
