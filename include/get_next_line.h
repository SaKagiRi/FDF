/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 02:20:44 by knakto            #+#    #+#             */
/*   Updated: 2025/01/12 02:20:44 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef LIMIT
#  define LIMIT 10000
# endif

typedef struct s_lst
{
	char			content[BUFFER_SIZE];
	size_t			len;
	struct s_lst	*next;
}	t_lst;

typedef struct s_var
{
	int		fd;
	int		eof;
	int		fin;
	t_lst	*word;
	t_lst	*run;
	size_t	offset;
	size_t	nlb;
}	t_var;

char	*get_next_line(int fd);

#endif
