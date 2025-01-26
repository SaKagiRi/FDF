/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:34:29 by knakto            #+#    #+#             */
/*   Updated: 2025/01/19 00:34:29 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static t_pixel	*add_content(char *content, int x, int z)
{
	t_pixel	*pixel;

	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		 return (NULL);
	pixel->all = ft_strdup(content);
	pixel->x = x;
	pixel->z = z;
	return (pixel);
}

static int	len_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i][0] != '\n')
	{
		i++;
	}
	free_split(arg);
	return (i);
}

static void	clear_line(int fd)
{
	char *line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static void	check_scale_map(t_map *map)
{
	int		fd;
	int		x;
	char	**arg;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	line = get_next_line(fd);
	map->width = len_arg(ft_split(line, ' '));
	map->height = 0;
	while (line)
	{
		x = -1;
		map->height++;
		arg = fsplit(line, ' ');
		while (arg[++x] && arg[x][0] != '\n')
			ft_lstadd_back(&map->head_y, ft_lstnew(add_content(arg[x], x + 1, map->height)));
		free_split(arg);
		if (x != map->width)
		{
			clear_line(fd);
			ft_lstclear(&map->head_y, del_all);
			ft_error("mapsize error. ");
		}
		line = get_next_line(fd);
	}
}

void	init_map(t_map *map, char *name_map)
{
	int	fd;

	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		ft_error("Error");
	map->map_name = name_map;
	dot_fdf(map);
	check_scale_map(map);
}
