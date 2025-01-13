/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:55 by knakto            #+#    #+#             */
/*   Updated: 2025/01/13 14:52:55 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	add_content(t_list *head, char *content)
{
	pnf("true");
}

int	check(char *str)
{
	return (1);
}

void	store(t_list *head, char *map)
{
	char	*line;
	char	**arg;
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Store Error", 1, UNFREE, NULL);
	line = get_next_line(fd);
	while (line)
	{
		arg = fsplit(line, ' ');
		i = -1;
		while (arg[++i])
		{
			if (!check(arg[i]))
				error_fail_check_in_store(arg, line, fd);
			else
				add_content(head, arg[i]);
		}
		free_split(arg);
		line = get_next_line(fd);
	}
	close(fd);
}
