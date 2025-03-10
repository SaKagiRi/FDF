/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:07:57 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 02:11:30 by knakto           ###   ########.fr       */
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
			pnf("%d,%X ", (int)map[i][j]->z, map[i][j]->color);
			j++;
		}
		pnf("\n");
		i++;
	}
}

void	print_bind(void)
{
	t_fdf	*fdf;
	t_list	*b;
	t_bind	*bind;

	fdf = get_t_fdf();
	b = fdf->bind;
	while (b)
	{
		bind = b->content;
		pnf("modifier->%d\nkey_1->%d\nkey_2->%d\nfunction->%d\n\n\n", bind->modifier, bind->key1, bind->key2, bind->function);
		b = b->next;
	}
	pnf("mouse = %d", fdf->mouse);
}

/* NOTE:
 * stage 1 {map control}
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
	// print_map();
	endstage_1();
}

/* NOTE:
 * stage 2 {config setting}
 * - read config and set value
 * - set keybind
 * - set function 
*/
void	stage_2(void)
{
	get_config_files();
	// print_bind();
}

/* NOTE:
 * stage 3 {MLX render}
 * - initmlx
 * - drawline function
 * - projection
 */
void	stage_3(void)
{
	initmlx();
	clear(0);
}

int	main(int c, char **v, char **env)
{
	if (c != 2)
		return (1);
	init();
	stage_1(v, env);
	stage_2();
	stage_3();
}
