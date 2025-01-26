/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:40:49 by knakto            #+#    #+#             */
/*   Updated: 2025/01/25 14:40:49 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	import_setting(t_map *map, char *line)
{
	char	*bind;

	if (ft_strncmp(line, "map_size ", 9) == 0)
		map->size = ft_atoi(line + 9);
	else if (ft_strncmp(line, "bind ", 5) == 0)
	{
		bind = fjoin(ft_strtrim(line + 5, " ,=\n"), ";");
		map->keybind = fjoin(map->keybind, bind);
		free(bind);
	}
	else if (ft_strncmp(line, "color ", 6) == 0)
		if (ft_strncmp(line + 6, "false", 4) == 0)
			map->map_color = false;
	free(line);
}

void	setting(t_map *map)
{
	int	fd;
	char	*line;

	fd = open(".fdf-profile", O_RDONLY);
	if (fd < 0)
	{
		map->setting_enable = false;
		return ;
	}
	map->setting_enable = true;
	map->size = 1;
	map->map_color = true;
	map->keybind = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		import_setting(map, line);
		line = get_next_line(fd);
	}
	close(fd);
}
