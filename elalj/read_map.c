/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:47:12 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/09 18:47:13 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map(t_data *data)
{
	int	i;
	int	columns;
	
	data->map_info.columns = 0;
	while (data->map_info.str[data->map_info.columns])
		data->map_info.columns++;
	data->map_info.map = malloc(sizeof(char *) * data->map_info.columns - 6);
	if (!data->map_info.map)
		return ;
	columns = 6;
	i = 0;
	while (data->map_info.str[columns])
	{
		data->map_info.map[i] =	ft_strdup(data->map_info.str[columns]);
		i++;
		columns++;
	}
	data->map_info.map[i] = NULL;
}

void	check_extension_map(char *file)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (file[i] != 'b')
		extension_err();
	if (file[i - 1] != 'u')
		extension_err();
	if (file[i - 2] != 'c')
		extension_err();
	if (file[i - 3] != '.')
		extension_err();
}

void	read_map(t_data *data, int fd)
{
	char *fullmap;
	char *line;

	fullmap = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		err_empty_map();
	while (line != NULL)
	{
		fullmap = ftt_strjoin(fullmap, line);
		free(line);
		line = get_next_line(fd);
	}
	data->map_info.str = ftt_split(fullmap, '\n');
	free(fullmap);
}