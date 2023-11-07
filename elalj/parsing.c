/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:56:57 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/07 12:56:58 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_map(int fd, t_data *data)
{
	char *fullmap;
	char *line;

	fullmap = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		print_and_exit(NULL);
	while (line != NULL)
	{
		fullmap = ftt_strjoin(fullmap, line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	data->map.str = ftt_split(fullmap, '\n');
	free(fullmap);
	fullmap = NULL;
}

void	find_cor_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.str[x])
	{
		y = 0;
		while (data->map.str[y])
		{
			if (data->map.str[x][y] == 'N'
				|| data->map.str[x][y] == 'S'
				|| data->map.str[x][y] == 'E'
				|| data->map.str[x][y] == 'W')
			{
				data->map.x = x;
				data->map.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}