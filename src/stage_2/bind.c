/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:23:48 by knakto            #+#    #+#             */
/*   Updated: 2025/03/09 18:21:25 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static t_bind	*ft_bind(bool modifier, char *bind, char *function)
{
	t_bind	*b;

	b = malloc(sizeof(t_bind));
	if (!b)
		return (NULL);
	b->modifier = 0;
	if (modifier)
	{
		b->modifier = 1;
		b->key1 = get_function_or_bind(bind, 1, b);
		b->function = get_function_or_bind(function, 2, NULL);
		return (b);
	}
	b->key2 = 0;
	b->key1 = get_function_or_bind(bind, 1, b);
	b->function = get_function_or_bind(function, 2, NULL);
	return (b);
}

void	binding(char *key, char *value)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (ft_strchr(key, '<') && ft_strchr(key, '>'))
		ft_lstadd_back(&fdf->bind, ft_lstnew(ft_bind(true, key, value)));
	else
		ft_lstadd_back(&fdf->bind, ft_lstnew(ft_bind(false, key, value)));
}
