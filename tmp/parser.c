/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:29:04 by knakto            #+#    #+#             */
/*   Updated: 2025/03/08 13:51:30 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	store_map(t_tool *tool)
{
	char	*join;
	char	*num;

	num = ft_itoa(tool->x);
	join = ft_strjoin("width =", num);
	ft_export(join);
	free(num);
	free(join);
	num = ft_itoa(tool->z);
	join = ft_strjoin("height =", num);
	ft_export(join);
	free(num);
	free(join);
}

void	replace_nextline(char	**str)
{
	int		i;
	char	*line;

	i = 0;
	line = *str;
	while (*(line + i))
	{
		if (*(line + i) == '\n')
			*(line + i) = ' ';
		i++;
	}
}

int	get_width_height(void)
{
	t_tool	tool;

	tool.status = 0;
	tool.z = 0;
	tool.mapname = ft_envget("mapname");
	tool.fd = open(tool.mapname, O_RDONLY);
	free(tool.mapname);
	tool.line = get_next_line(tool.fd);
	while (tool.line)
	{
		tool.z += 1;
		replace_nextline(&tool.line);
		tool.temp_x = count_word(tool.line, ' ');
		if (tool.z == 1)
			tool.x = tool.temp_x;
		else if (tool.x != tool.temp_x)
			tool.status = 1;
		free(tool.line);
		tool.line = get_next_line(tool.fd);
	}
	close(tool.fd);
	if (tool.status)
		return (0);
	store_map(&tool);
	return (1);
}

static int	get_file_type(char *file_name)
{
	int		len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	len -= 4;
	if (ft_strncmp(file_name + len, ".fdf", 4) == 0)
		return (1);
	return (0);
}

int	check_file_name(void)
{
	char	*file_name;
	int		status;
	int		fd;

	file_name = ft_envget("mapname");
	if (!file_name)
		status = 0;
	status = get_file_type(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		status = 0;
	free(file_name);
	if (!status)
		return (0);
	return (1);
}
