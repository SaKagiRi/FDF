/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:50:59 by knakto            #+#    #+#             */
/*   Updated: 2025/03/12 02:17:45 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	usefunction2(int f, t_fdf *fdf)
{
	if (f == FT_MOVE_LEFT)
		fdf->px += fdf->move_size;
	else if (f == FT_MOVE_RIGHT)
		fdf->px -= fdf->move_size;
	else if (f == ISO)
		set_view(ISO);
	else if (f == BIRDVIEW)
		set_view(BIRDVIEW);
	else if (f == FT_EXIT)
		ft_exit(fdf);
	fdf->change = true;
}

void	usefunction(int f)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (f == FT_ZOOM_IN)
		ft_zoom(fdf, 1);
	else if (f == FT_ZOOM_OUT)
		ft_zoom(fdf, 2);
	else if (f == FT_ROTATE_X_UP)
		ft_rotate(fdf, 1);
	else if (f == FT_ROTATE_X_DOWN)
		ft_rotate(fdf, 2);
	else if (f == FT_ROTATE_Y_UP)
		ft_rotate(fdf, 3);
	else if (f == FT_ROTATE_Y_DOWN)
		ft_rotate(fdf, 4);
	else if (f == FT_ROTATE_Z_UP)
		ft_rotate(fdf, 5);
	else if (f == FT_ROTATE_Z_DOWN)
		ft_rotate(fdf, 6);
	else if (f == FT_MOVE_UP)
		fdf->py += fdf->move_size;
	else if (f == FT_MOVE_DOWN)
		fdf->py -= fdf->move_size;
	usefunction2(f, fdf);
}

void	control(mlx_key_data_t d, void *fdf)
{
	static mlx_key_data_t	m;
	t_list					*node;
	t_bind					*b;

	default_config(d);
	if (d.modifier == 0)
		m = d;
	node = ((t_fdf *)fdf)->bind;
	while (node)
	{
		b = node->content;
		if (b->modifier == 0)
		{
			if (b->key1 == d.key)
				usefunction(b->function);
		}
		else if (b->modifier == 1)
		{
			if (d.key == b->key2 && d.action == 1 \
				&& m.key == b->key1 && m.action == 1 && d.modifier == 2)
				usefunction(b->function);
		}
		node = node->next;
	}
}
