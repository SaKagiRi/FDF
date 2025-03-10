/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:59:32 by knakto            #+#    #+#             */
/*   Updated: 2025/03/10 02:22:12 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	set_value_variable(char *key, bool set)
{
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (!ft_strncmp(key, "mouse", 5))
		fdf->mouse = set;
}

void	variable(char *key, char *value)
{
	bool	set;
	char	*str;

	str = ft_strtrim(value, " \n");
	if (!ft_strncmp(value, "true", 5))
		set = true;
	else if (!ft_strncmp(value, "false", 6))
		set = false;
	else
	{
		free(str);
		 return ;
	}
	free(str);
	set_value_variable(key, set);
}
