/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 07:56:00 by knakto            #+#    #+#             */
/*   Updated: 2025/03/08 17:15:28 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <limits.h>
# include <math.h>
# include "../lib/KML/include/kml.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define CONFIG ".kconf"
# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265

typedef enum e_type
{
	SET_Y,
	SET_COLOR,
}	t_name;

typedef struct s_point
{
	long	color;
	float		y;
	float		plot_x;
	float		plot_y;
}	t_point;

typedef struct s_tool
{
	char	*mapname;
	char	*line;
	int		x;
	int		z;
	int		temp_x;
	int		fd;
	int		status;
}	t_tool;

typedef struct s_fdf
{
	int				map_fd;
	int				config_fd;
	bool			err;
	bool			color;
	bool			change;
	float			height;
	float			width;
	float			px;
	float			py;
	float			zoom;
	float			x_degree;
	float			z_degree;
	float			y_degree;
	t_point			***map;
	t_list			*all_map;
	void			**endline;
	void			**headline;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}	t_fdf;

typedef struct s_draw
{
	char	axis;
	long	col1;
	long	col2;
	float	rx;
	float	rz;
	float	x1;
	float	z1;
	float	x2;
	float	z2;
	float	dx;
	float	dy;
	float	diff;
	float	inc;
}	t_draw;

void	init(void);
void	clear(int stage);
t_fdf	*get_t_fdf(void);
void	pars_map_name(char **v, char **env);
void	store_map(void);

#endif
