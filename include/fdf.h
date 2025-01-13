/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:53:19 by knakto            #+#    #+#             */
/*   Updated: 2025/01/13 14:53:19 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/KML/include/kml.h"
# include "error.h"
#include "fcntl.h"

typedef struct s_pixel
{
	long	color;
	int		height;
	int		x;
	int		y;
}	t_pixel;

void	store(t_list *head, char *map);

#endif
