/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readconfig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:05:11 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:44:51 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	arglen(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i][0] != '\n')
		i++;
	return (i);
}

void	set_bind(char *line)
{
	char	**split;

	if (ft_strncmp(line, "set -b", 6))
		return ;
	split = ft_split(line, ' ');
	if (arglen(split) != 4)
	{
		free_split(split);
		return ;
	}
	binding(split[2], split[3]);
	free_split(split);
}

void	set_variable(char *line)
{
	char	**split;

	if (ft_strncmp(line, "set -v", 6))
		return ;
	split = ft_split(line, ' ');
	if (arglen(split) != 4)
	{
		free_split(split);
		return ;
	}
	variable(split[2], split[3]);
	free_split(split);
}

void	read_config(t_fdf *fdf)
{
	char	*line;
	int		fd;

	fd = fdf->config_fd;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "set ", 4))
		{
			set_bind(line);
			set_variable(line);
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	get_config_files(void)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	set_default();
	if (fdf->config_fd <= 0)
		return ;
	read_config(fdf);
}
