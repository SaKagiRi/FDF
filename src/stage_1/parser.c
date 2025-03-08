/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:19:08 by knakto            #+#    #+#             */
/*   Updated: 2025/03/08 17:53:24 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	check_fdf_file(char *name_map)
{
	int		fd;
	int		len;
	t_fdf	*fdf;

	fdf = get_t_fdf();
	if (!name_map)
		clear(1);
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		clear(1);
	len = ft_strlen(name_map);
	if (ft_strncmp(name_map + (len - 4), ".fdf", 4))
		clear(1);
	fdf->map_fd = fd;
	return (1);
}

void	check_config_file(char **env)
{
	char	*name_config;
	int		i;
	int		fd;
	t_fdf	*fdf;

	i = 0;
	name_config = NULL;
	while (env[i] && !ft_strncmp(env[i], "HOME=", 5))
		i++;
	if (!env[i])
		return ;
	name_config = ft_strdup(env[i]);
	name_config = fjoin(name_config, CONFIG);
	fd = open(name_config, O_RDONLY);
	free(name_config);
	if (fd < 0)
		return ;
	fdf = get_t_fdf();
	fdf->config_fd = fd;
}

void	pars_map_name(char **v, char **env)
{
	if (!check_fdf_file(v[1]))
		clear(1);
	check_config_file(env);
}
