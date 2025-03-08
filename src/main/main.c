/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:07:57 by knakto            #+#    #+#             */
/*   Updated: 2025/03/08 18:12:42 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	print_map(void)
{
	t_fdf	*fdf;
	t_point	***map;
	int		i;
	int		j;

	i = 0;
	fdf = get_t_fdf();
	map = fdf->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			pnf("%d,%X ", (int)map[i][j]->y, map[i][j]->color);
			j++;
		}
		pnf("\n");
		i++;
	}
}

/* NOTE:
 * what stage 1 do.
 * - get width and height 
 * - check and get fd config file
 * - readmap to linked list
 * - check error parser
 * - decript store to t_point *** (map point* 2D)
*/
void	stage_1(char **v, char **env)
{
	pars_map_name(v, env);
	store_map();
	print_map();
	clear(0);
}

/* NOTE:
 * what stage 2 do.
 * - read config and set value
 * - init mlx and set texture
 * - first drawing
*/
void	stage_2(void)
{
}

int	main(int c, char **v, char **env)
{
	if (c != 2)
		return (1);
	init();
	stage_1(v, env);
}
