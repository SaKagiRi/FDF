/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:44:13 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 22:26:42 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	utils_key2(char *f)
{
	if (!ft_strncmp(f, "R_CTRL", 6))
		return (MLX_KEY_RIGHT_CONTROL);
	else if (!ft_strncmp(f, "L_CTRL", 6))
		return (MLX_KEY_LEFT_CONTROL);
	return (0);
}

int	utils_key(char *f)
{
	if (ft_strlen(f) == 1)
		return (ft_toupper(f[0]));
	else if (!ft_strncmp(f, "SPACE", 5))
		return (MLX_KEY_SPACE);
	else if (!ft_strncmp(f, "ESCAPE", 6))
		return (MLX_KEY_ESCAPE);
	else if (!ft_strncmp(f, "RETURN", 6))
		return (MLX_KEY_ENTER);
	else if (!ft_strncmp(f, "TAB", 3))
		return (MLX_KEY_TAB);
	else if (!ft_strncmp(f, "UP", 2))
		return (MLX_KEY_UP);
	else if (!ft_strncmp(f, "DOWN", 4))
		return (MLX_KEY_DOWN);
	else if (!ft_strncmp(f, "LEFT", 4))
		return (MLX_KEY_LEFT);
	else if (!ft_strncmp(f, "RIGHT", 5))
		return (MLX_KEY_RIGHT);
	else if (!ft_strncmp(f, "L_SHIFT", 7))
		return (MLX_KEY_LEFT_SHIFT);
	else if (!ft_strncmp(f, "R_SHIFT", 7))
		return (MLX_KEY_RIGHT_SHIFT);
	return (utils_key2(f));
}

int	utils_fnc2(char *f)
{
	if (!ft_strncmp(f, "ft_escape", 9))
		return (FT_EXIT);
	else if (!ft_strncmp(f, "iso", 3))
		return (ISO);
	else if (!ft_strncmp(f, "birdview", 8))
		return (BIRDVIEW);
	return (0);
}

int	utils_fnc(char *f)
{
	if (!ft_strncmp(f, "ft_zoom_in", 10))
		return (FT_ZOOM_IN);
	else if (!ft_strncmp(f, "ft_zoom_out", 11))
		return (FT_ZOOM_OUT);
	else if (!ft_strncmp(f, "ft_rotate_x_down", 16))
		return (FT_ROTATE_X_DOWN);
	else if (!ft_strncmp(f, "ft_rotate_x_up", 14))
		return (FT_ROTATE_X_UP);
	else if (!ft_strncmp(f, "ft_rotate_y_down", 16))
		return (FT_ROTATE_Y_DOWN);
	else if (!ft_strncmp(f, "ft_rotate_y_up", 14))
		return (FT_ROTATE_Y_UP);
	else if (!ft_strncmp(f, "ft_rotate_z_down", 16))
		return (FT_ROTATE_Z_DOWN);
	else if (!ft_strncmp(f, "ft_rotate_z_up", 14))
		return (FT_ROTATE_Z_UP);
	else if (!ft_strncmp(f, "ft_move_up", 10))
		return (FT_MOVE_UP);
	else if (!ft_strncmp(f, "ft_move_down", 12))
		return (FT_MOVE_DOWN);
	else if (!ft_strncmp(f, "ft_move_left", 12))
		return (FT_MOVE_LEFT);
	else if (!ft_strncmp(f, "ft_move_right", 13))
		return (FT_MOVE_RIGHT);
	return (utils_fnc2(f));
}

int	get_function_or_bind(char *f, int sw, t_bind *bind)
{
	int		res;
	char	*set;
	char	**arg;

	if (sw == 2)
		return (utils_fnc(f));
	else if (sw == 1)
	{
		if (ft_strchr(f, '<') && ft_strchr(f, '>'))
		{
			set = ft_strtrim(f, "<>");
			arg = fsplit(set, '-');
			bind->key2 = utils_key(arg[1]);
			res = utils_key(arg[0]);
			free_split(arg);
			return (res);
		}
		return (utils_key(f));
	}
	return (0);
}
