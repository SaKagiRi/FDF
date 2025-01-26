/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:52:14 by knakto            #+#    #+#             */
/*   Updated: 2025/01/12 19:52:14 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_pixel	*convert(t_list *node)
{
	return (node->content);
}

void	del_all(void *content)
{
	t_pixel *pixel;

	pixel = (t_pixel *)content;
	free(pixel->all);
	free(content);
}

void	del(void *content)
{
	free(content);
}

void	clear(t_map *map)
{
	ft_lstclear(&map->head_y, del);
}

#include <stdio.h>
void	print(t_map *map)
{
	t_list	*node;
	int	i;

	pnf("%s\n", map->map_name);
	node = map->head_y;
	while (node)
	{
		i = map->width;
		while (i--)
		{
			printf("%d,%d,%d,[%ld] \n", convert(node)->x, convert(node)->y, convert(node)->z, convert(node)->color);
			node = node->next;
		}
		pnf("\n");
	}
}

void	read_status_map(t_map *map)
{
	pnf("height-> %d\n", map->height);
	pnf("width-> %d\n", map->width);
	pnf("name-> %s\n", map->map_name);
}

int	main(int c, char **v)
{
	t_map	map;

	if (c != 2)
		return (1);

	map.head_y = NULL;
	init_map(&map, v[1]);
	add_y_and_color(&map);
	print(&map);
	//read_status_map(&map);
	clear(&map);
	return (0);
}
