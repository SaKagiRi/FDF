/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:36:37 by knakto            #+#    #+#             */
/*   Updated: 2025/01/24 18:36:37 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	read_status(t_map *map)
{
	t_list *node;

	node = map->head_y;
	pnf("%d-%d\n", map->width, map->height);
	pnf("-->%d\n", map->setting_enable);
	pnf("-->%d\n", map->size);
	pnf("-->%s\n", map->keybind);
	while (node)
	{
		pnf("(%d,%d,%d)[%d] ", ((t_pixel *)node->content)->x, ((t_pixel *)node->content)->y, ((t_pixel *)node->content)->z, ((t_pixel *)node->content)->color);
		if (((t_pixel *)node->content)->x == map->width)
			pnf("\n");
		node = node->next;
	}
}

void	del(void *content)
{
	//free(((t_pixel *)content)->all);
	free(content);
}

int	mains(int c, char **v)
{
	t_map	map;

	if (c != 2 || !pars_simple_map(v[1]))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	setting(&map);
	init_map(&map, v[1]);
	split_color(&map);
	read_status(&map);
	if (map.setting_enable == 1)
		free(map.keybind);
	ft_lstclear(&map.head_y, del);
}
