/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:03:33 by knakto            #+#    #+#             */
/*   Updated: 2025/03/05 16:36:56 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	get_home_path(char	**env)
{
	int	i;

	i = 0;
	while (*(env + i))
	{
		if (ft_strncmp(*(env + i), "HOME=", 5) == 0)
		{
			ft_export(*(env + i));
			break ;
		}
		i++;
	}
}

void	init(char *v, char	**envp)
{
	char	*mapname;

	ft_envinit();
	get_home_path(envp);
	mapname = ft_strjoin("mapname =", v);
	ft_export(mapname);
	free(mapname);
}
