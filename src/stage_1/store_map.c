/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:24:43 by knakto            #+#    #+#             */
/*   Updated: 2025/03/10 04:37:50 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	readmap_and_store_height(t_fdf *fdf)
{
	int		height;
	t_list	*map;
	char	*line;

	height = 0;
	line = get_next_line(fdf->map_fd);
	while (line)
	{
		height++;
		if (height == 1)
		{
			fdf->all_map = ft_lstnew(line);
			map = fdf->all_map;
		}
		else
		{
			map->next = ft_lstnew(line);
			map = map->next;
		}
		line = get_next_line(fdf->map_fd);
	}
	fdf->height = height;
}

static long	check_number(char *nb, int type)
{
	long	temp;

	if (type == SET_Y)
	{
		temp = ft_atol(nb);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		return (temp);
	}
	else if (type == SET_COLOR)
	{
		temp = 0xFFF;
		if (!nb)
			return (temp);
		if (ft_strncmp(nb + 1, "0x", 2))
			return (temp);
		temp = ft_htol(nb + 3);
		return (temp);
	}
	return (0);
}

t_point	**decript_line(char *line)
{
	char	**split;
	t_point	**res;
	t_fdf	*fdf;
	int		temp;
	int		i;

	line = ft_strtrim(line, " \n");
	fdf = get_t_fdf();
	temp = (float)count_word(line, ' ');
	if (temp != fdf->width)
		fdf->err = true;
	split = fsplit(line, ' ');
	res = malloc(sizeof(t_point *) * (temp + 1));
	i = 0;
	while (split[i])
	{
		res[i] = malloc(sizeof(t_point));
		res[i]->z = (float)check_number(split[i], SET_Y);
		res[i]->color = check_number(ft_strchr(split[i], ','), SET_COLOR);
		i++;
	}
	res[i] = NULL;
	free_split(split);
	return (res);
}

void	decriptmap_and_store_width(t_fdf *fdf)
{
	char	*temp;
	t_list	*map;
	int		i;

	map = fdf->all_map;
	temp = ft_strtrim((char *)map->content, " \n");
	fdf->width = count_word(temp, ' ');
	free(temp);
	fdf->map = malloc(sizeof(t_point **) * (fdf->height + 1));
	i = 0;
	while (map && i < fdf->height)
	{
		fdf->map[i] = decript_line(map->content);
		i++;
		map = map->next;
	}
	fdf->map[i] = NULL;
}

void	store_map(void)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	readmap_and_store_height(fdf);
	decriptmap_and_store_width(fdf);
	if (fdf->err)
		clear(1);
}
