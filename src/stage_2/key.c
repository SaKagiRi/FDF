/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:44:13 by knakto            #+#    #+#             */
/*   Updated: 2025/03/09 18:39:19 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	utils_key(char *f)
{
	if (ft_strlen(f) == 1)
		return (ft_toupper(f[0]));
	if (!ft_strncmp(f, "SPACE", 5))
		return (MLX_KEY_SPACE);
	if (!ft_strncmp(f, "RETURN", 6))
		return (MLX_KEY_ENTER);
	if (!ft_strncmp(f, "TAB", 3))
		return (MLX_KEY_TAB);
	if (!ft_strncmp(f, "UP", 2))
		return (MLX_KEY_UP);
	if (!ft_strncmp(f, "DOWN", 4))
		return (MLX_KEY_DOWN);
	if (!ft_strncmp(f, "LEFT", 4))
		return (MLX_KEY_LEFT);
	if (!ft_strncmp(f, "RIGHT", 5))
		return (MLX_KEY_RIGHT);
	if (!ft_strncmp(f, "L_SHIFT", 7))
		return (MLX_KEY_LEFT_SHIFT);
	if (!ft_strncmp(f, "R_SHIFT", 7))
		return (MLX_KEY_RIGHT_SHIFT);
	if (!ft_strncmp(f, "R_CTRL", 6))
		return (MLX_KEY_RIGHT_CONTROL);
	if (!ft_strncmp(f, "L_CTRL", 6))
		return (MLX_KEY_LEFT_CONTROL);
	return (0);
}

int	get_function_or_bind(char *f, int sw, t_bind *bind)
{
	int		res;
	char	*set;
	char	**arg;

	if (sw == 2)
	{
		return (1);
	}
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
