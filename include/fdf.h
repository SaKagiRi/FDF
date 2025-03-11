/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 07:56:00 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 16:51:09 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "../lib/KML/include/kml.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define CONFIG "/.kconf"
# define WIDTH 700
# define HEIGHT 500
# define PI 3.14159


typedef enum e_type
{
	SET_Y,
	SET_COLOR,
}	t_name;

typedef struct s_point
{
	long		color;
	float		z;
	float		x;
	float		y;
	float		plot_z;
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

typedef struct s_bind
{
	bool	modifier;
	int		key1;
	int		key2;
	int		function;
}	t_bind;

typedef struct s_fdf
{
	int				map_fd;
	int				config_fd;
	bool			err;
	bool			color;
	bool			change;
	bool			mouse;
	float			height;
	float			width;
	float			px;
	float			py;
	float			zoom;
	float			x_degree;
	float			z_degree;
	float			y_degree;
	t_list			*cache;
	t_list			*bind;
	t_point			***map;
	t_list			*all_map;
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

typedef	struct	s_cache
{
	float		zoom;
	float		px;
	float		py;
	float		x_degree;
	float		y_degree;
	float		z_degree;
	mlx_texture_t	*texture;
}	t_cache;

void	init(void);
void	clear(int stage);
t_fdf	*get_t_fdf(void);
void	pars_map_name(char **v, char **env);
void	store_map(void);
void	endstage_1(void);
void	binding(char *key, char *value);
int		get_function_or_bind(char *f, int sw, t_bind *bind);
void	get_config_files(void);
void	variable(char *key, char *value);
int	draw_texture(mlx_texture_t *texture, float x, float y, size_t rgb);
mlx_texture_t	*new_texture(size_t w, size_t h);
void	bresenham(t_fdf *fdf ,t_point start, t_point stop);
void	initmlx(void);
void	setpoint(t_point *p, t_fdf *fdf);
void	point_set(void);
void	connect_point(void);
void	fill_background(mlx_texture_t *texture);
float	ft_abs(float a);
void	cache(t_fdf *fdf);

#endif
