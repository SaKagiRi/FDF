/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:29:34 by knakto            #+#    #+#             */
/*   Updated: 2025/03/08 17:53:51 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_error(int error_status)
{
	if (error_status != 0)
		ft_putstr_fd("Error\n", 2);
	exit(error_status);
}

void	ft_free_point(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (fdf->map[i])
	{
		j = 0;
		while (fdf->map[i][j])
		{
			free(fdf->map[i][j]);
			j++;
		}
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
}

void	clear(int stage)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (stage == 0)
	{
		close(fdf->map_fd);
		close(fdf->config_fd);
		ft_free_point(fdf);
		ft_error(0);
	}
	else if (stage == 1)
	{
		close(fdf->map_fd);
		close(fdf->config_fd);
		ft_free_point(fdf);
		ft_error(1);
	}
	ft_error(0);
}
