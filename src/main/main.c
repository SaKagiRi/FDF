/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:07:57 by knakto            #+#    #+#             */
/*   Updated: 2025/03/13 18:27:04 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
	{
		pnf("Usage: ./build/fdf [map-name].fdf\n");
		return (1);
	}
	init();
	stage_1(v, env);
	stage_2();
	stage_3();
}
