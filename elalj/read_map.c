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

char	*remtabs(char *line)
{
	int		i;
	int		c;
	char	*dest;

	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			c++;
		i++;
	}
	dest = (char *)ft_calloc(ft_strlen(line) - c, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] != '\t')
		{
			dest[c] = line[i];
			c++;
		}
		i++;
	}
	dest[c] = '\0';
	return (dest);
}
void	init_map(t_data *data)
{
	int	columns;
	int	i;

	columns = 0;
	while (data->map_info.str[columns])
		columns++;
	data->map_info.map = malloc(sizeof(char *) * columns - 6);
	if (!data->map_info.map)
		return ;
	columns = 6;
	i = 0;
	while (data->map_info.str[columns])
	{
		data->map_info.map[i] =	ft_strdup(remtabs(data->map_info.str[columns]));
		i++;
		columns++;
	}
	data->map_info.map[i] = NULL;
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