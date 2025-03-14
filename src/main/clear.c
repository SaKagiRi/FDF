/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:29:34 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 02:03:33 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	clearcache(void *c)
{
	mlx_delete_texture(((t_cache *)c)->texture);
	free(c);
}

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

void	clear2(int stage, t_fdf *fdf)
{
	if (stage == 2)
	{
		close(fdf->config_fd);
		ft_lstclear(&fdf->bind, free);
		ft_free_point(fdf);
	}
	else if (stage == 3)
	{
		close(fdf->config_fd);
		ft_lstclear(&fdf->bind, free);
		ft_free_point(fdf);
		ft_lstclear(&fdf->cache, clearcache);
	}
	ft_error(1);
}

void	clear(int stage)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (stage == 0)
	{
		close(fdf->config_fd);
		close(fdf->map_fd);
		ft_lstclear(&fdf->bind, free);
		ft_free_point(fdf);
		ft_lstclear(&fdf->cache, clearcache);
		ft_error(0);
	}
	else if (stage == 1)
	{
		close(fdf->config_fd);
		close(fdf->map_fd);
	}
	clear2(stage, fdf);
}
