/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 02:51:28 by knakto            #+#    #+#             */
/*   Updated: 2025/01/21 02:51:28 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int store_y_color(t_list *node, int len)
{
	char	**arg;

	if (ft_atol(convert(node)->all) > 2147483647 \
		|| ft_atol(convert(node)->all) < -2147483648)
	{
		free(convert(node)->all);
		return (-1);
	}
	arg = fsplit(convert(node)->all, ',');
	if (arg[0] && arg[1] && !arg[2])
	{
		convert(node)->y = ft_atoi(arg[0]);
		convert(node)->color = ft_htol(arg[1] + 2);
	}
	else if (arg[0] && !arg[1])
	{
		convert(node)->y = ft_atoi(arg[0]);
		convert(node)->color = -1;
	}
	else
	{
		free_split(arg);
		return (0);
	}
	free_split(arg);
	return (1);
}

void	add_y_and_color(t_map *map)
{
	t_list	*node;
	char	**arg;
	int		len;
	int		status;

	node = map->head_y;
	while (node)
	{
		status = store_y_color(node, len);
		if (status != 1)
		{
			ft_lstclear(&map->head_y, del_all);
			ft_error("Error map format");
		}
		node = node->next;
	}
}

int	check_number(t_map *map)
{
	t_list	*node;
	long	number;

	node = map->head_y;
	while (node)
	{
		number = ft_atol(convert(node)->all);
		pnf("%d\n", number);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		node = node->next;
	}
	return (1);
}
