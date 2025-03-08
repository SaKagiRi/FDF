/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:03:38 by knakto            #+#    #+#             */
/*   Updated: 2025/03/05 16:32:51 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_list	**getmap(void)
{
	static t_list	*map = NULL;

	return (&map);
}

t_fdf	*get_t_fdf(void)
{
	static t_fdf	fdf;

	return (&fdf);
}
