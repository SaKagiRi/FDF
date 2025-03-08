/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:52:56 by knakto            #+#    #+#             */
/*   Updated: 2025/03/05 21:26:35 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <limits.h>

static void	storecolor(t_point *pixel, char *point)
{
	char	**split;
	char	*temp;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	temp = ft_strrchr(point, ',');
	if (ft_find(point, ',') == 0 || ft_strncmp(temp + 1, "0x", 2) != 0)
		pixel->color = 4294967295;
	else if (ft_find(point, ',') == 1)
	{
		pixel->color = ft_htol(temp + 3);
		fdf->color = 1;
	}
}

t_point	*decript_map(char *point, int x, int z)
{
	t_point	*pixel;
	char	**split;
	long	check_int;
	int		y;

	pixel = malloc(sizeof(t_point));
	if (!pixel)
		return (NULL);
	check_int = ft_atol(point);
	if (check_int > INT_MAX || check_int < INT_MIN)
		y = 0;
	else
		y = ft_atoi(point);
	storecolor(pixel, point);
	pixel->x = x;
	pixel->y = y;
	pixel->z = z;
	return (pixel);
}

static void	add_to_list(char *line, int z)
{
	t_list	*node;
	int		i;
	char	**arg;
	t_list	**map;

	arg = fsplit(line, ' ');
	i = 0;
	map = getmap();
	if (!*map)
	{
		*map = ft_lstnew(decript_map(arg[i], i + 1, z));
		i++;
	}
	node = ft_lstlast(*map);
	while (!node->next && arg[i] && arg[i][0] != '\n')
	{
		node->next = ft_lstnew(decript_map(arg[i], i + 1, z));
		// pnf("node->next->x = %d\n", ((t_point *)node->next->content)->x);
		node = node->next;
		i++;
	}
	free_split(arg);
}

void	readmapline(int fd)
{
	char	*line;
	char	**split;
	int		z;

	line = get_next_line(fd);
	z = 0;
	while (line)
	{
		z += 1;
		add_to_list(line, z);
		line = get_next_line(fd);
	}
}

void	printmap(void)
{
	t_list	*node;

	node = *getmap();
	while (node)
	{
		pnf("(%d,%d,%d)[%d] ", ((t_point *)node->content)->x, ((t_point *)node->content)->y, ((t_point *)node->content)->z, ((t_point *)node->content)->color);
		pnf("\n");
		node = node->next;
	}
}

void	readmap(void)
{
	char	*mapname;
	t_list	*map;
	t_list	*node;
	int		fd;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	fdf->color = 0;
	mapname = ft_envget("mapname");
	fd = open(mapname, O_RDONLY);
	free(mapname);
	readmapline(fd);
	printmap();
}
