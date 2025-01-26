/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:00:58 by knakto            #+#    #+#             */
/*   Updated: 2025/01/25 17:00:58 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	f_split_color(void *content)
{
	t_pixel	*pxl;
	char	*temp;
	long	check_int;

	pxl = (t_pixel *)content;
	check_int = ft_atol(pxl->all);
	if (check_int > INT_MAX || check_int < INT_MIN)
		pxl->y = 0;
	else
		pxl->y = ft_atoi(pxl->all);
	temp = ft_strrchr(pxl->all, ',');
	if (!temp || ft_strncmp(temp + 1, "0x", 2) != 0)
		pxl->color = 0;
	else
		pxl->color = ft_htol(temp + 3);
	free(pxl->all);
}

static void	f_del_color(void *content)
{
	t_pixel	*pxl;

	pxl = (t_pixel *)content;
	pxl->color = 0;
}

static void	del_map(void *content)
{
	free(content);
}

static int	fix_map(void *content, void *data_ref)
{
	t_pixel *pxl;

	pxl = (t_pixel *)content;
	return (pxl->x > *((int *)data_ref) || pxl->z > *((int *)data_ref));
}

void	split_color(t_map *map)
{
	ft_lstiter(map->head_y, f_split_color);
	if (map->setting_enable == 0)
		return ;
	if (map->map_color == 0)
	{
		ft_lstiter(map->head_y, f_del_color);
		return ;
	}
	//if (map->size > 1)
		//ft_lstremove_if(&map->head_y, (void *)&map->size, fix_map, del_map);

}
