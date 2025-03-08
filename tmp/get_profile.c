/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_profile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:37:53 by knakto            #+#    #+#             */
/*   Updated: 2025/02/24 17:13:20 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	encript_bind(char *line)
{
	char	*bind;
	char	**arg;
	char	*key;
	char	*value;
	char	*exp;

	arg = ft_split(line + 5, '=');
	key = ft_strtrim(arg[0], " ");
	value = ft_strtrim(arg[1], " ");
	bind = ft_envget("bind");
	if (bind)
		bind = fjoin(bind, ",");
	else
		bind = ft_strdup("");
	bind = fjoin(bind, key);
	bind = fjoin(bind, ":");
	bind = fjoin(bind, value);
	exp = ft_strjoin("bind=", bind);
	ft_export(exp);
	free(exp);
	free(key);
	free(value);
	free(bind);
	free_split(arg);
}

void	read_dotsfile(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "bind", 4) == 0 && ft_find(line, '=') == 1)
			encript_bind(line);
		if (ft_strncmp(line, "mouse", 5) == 0)
			ft_export(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_profile(void)
{
	char	*dotsfile;
	int		status;
	int		fd;

	dotsfile = ft_envget("dotsfile");
	if (!dotsfile)
		dotsfile = fjoin(ft_envget("HOME"), "/.kconf");
	fd = open(dotsfile, O_RDONLY);
	if (fd < 0)
	{
		ft_export("config = false");
		free(dotsfile);
		return ;
	}
	free(dotsfile);
	ft_export("config = true");
	read_dotsfile(fd);
}
