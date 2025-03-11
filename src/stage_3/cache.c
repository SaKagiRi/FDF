/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:53:22 by knakto            #+#    #+#             */
/*   Updated: 2025/03/11 16:47:44 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	*store_cache(t_fdf *fdf)
{
	t_cache	*c;

	c = malloc(sizeof(t_cache));
	if (!c)
		return (NULL);
	c->zoom = fdf->zoom;
	c->px = fdf->px;
	c->py = fdf->py;
	c->x_degree = fdf->x_degree;
	c->y_degree = fdf->y_degree;
	c->z_degree = fdf->z_degree;
	c->texture = fdf->texture;
	return (c);
}

void	create_new_img(t_fdf *fdf)
{
	fdf->texture = new_texture(WIDTH, HEIGHT);
	point_set();
	connect_point();
	ft_lstadd_back(&fdf->cache, ft_lstnew(store_cache(fdf)));
}

t_cache	*check_config(t_fdf *fdf)
{
	t_cache *c;
	t_list	*node;

	node = fdf->cache;
	while (node)
	{
		c = node->content;
		if (c->px == fdf->px && c->py == fdf->py && c->zoom == fdf->zoom \
			&& c->x_degree == fdf->x_degree \
			&& c->y_degree == fdf->y_degree \
			&& c->z_degree == fdf->z_degree)
			return (c);
		node = node->next;
	}
	return (NULL);
}

void	find_img(t_fdf *fdf)
{
	t_cache	*c;

	c = check_config(fdf);
	if (!c)
	{
		create_new_img(fdf);
		return ;
	}
	fdf->texture = c->texture;
}

/* NOTE:
 * - linked list cache if all as same config return texture
 *
*/
void	cache(t_fdf *fdf)
{
	if (!fdf->cache)
		create_new_img(fdf);
	find_img(fdf);
}
