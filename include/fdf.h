/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:53:19 by knakto            #+#    #+#             */
/*   Updated: 2025/01/13 14:53:19 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/KML/include/kml.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_setting
{
}	t_setting;

typedef struct s_pixel
{
	char	*all;
	long	color;
	int		z;
	int		x;
	int		y;
}	t_pixel;

typedef struct s_map
{
	int			height;
	int			width;
	char		*map_name;
	t_list		*head_y;
	bool		setting_enable;
	bool		map_color;
	int			size;
	char		*keybind;
}	t_map;

int	pars_simple_map(char *map);
void	init_map(t_map *map, char *name_map);
void	setting(t_map *map);
void	split_color(t_map *map);
/*void	del_all(void *content);

void	ft_error(char *text);
void	init_map(t_map *map, char *name_map);
void	dot_fdf(t_map *map);
void	store_map(t_map *map);

t_pixel	*convert(t_list *node);

int	check_number(t_map *map);
void	add_y_and_color(t_map *map);
*/
#endif
