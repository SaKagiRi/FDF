/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:37:14 by knakto            #+#    #+#             */
/*   Updated: 2025/01/25 14:37:14 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_pixel	*add_content(int x, int z, char *all)
{
	t_pixel	*pixel;

	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		return (NULL);
	pixel->x = x;
	pixel->z = z;
	pixel->all = ft_strdup(all);
	return (pixel);
}

static void	add_list(char *line, t_map *map)
{
	t_list *node;
	int		i;
	char	**arg;

	arg = fsplit(line, ' ');
	i = 0;
	if (!map->head_y)
	{
		map->head_y = ft_lstnew(add_content(i + 1, map->height, arg[i]));
		i++;
	}
	node = ft_lstlast(map->head_y);
	while (!node->next && arg[i] && arg[i][0] != '\n')
	{
		node->next = ft_lstnew(add_content(i + 1, map->height, arg[i]));
		node = node->next;
		i++;
	}
	free_split(arg);
	if (i > map->width)
		map->width = i;
}

static void	read_map(t_map *map)
{
	int	fd;
	int	i;
	char	*line;
	char	**arg;

	fd = open(map->map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		add_list(line, map);
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_map(t_map *map, char *name_map)
{
	map->map_name = name_map;
	map->head_y=NULL;
	map->height = 0;
	map->width = 0;
	read_map(map);
}

int	pars_simple_map(char *map)
{
	int	len;
	int	fd;
	int	status;
	char *name_map;

	name_map = ft_strdup(map);
	len = ft_strlen(name_map);
	status = 1;
	if (len < 5)
		status = 0;
	len = len - 4;
	if (ft_strncmp(name_map + len, ".fdf", 5) != 0)
		status = 0;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		status = 0;
	free(name_map);
	if (status != 1)
		return (0);
	return (1);
}
