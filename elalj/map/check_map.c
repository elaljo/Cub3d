/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:51:21 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/13 14:51:24 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3d.h"

void	found_tab_inside(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (data->map_info.map[i])
	{

		str = ft_strdup(data->map_info.map[i]);
		str = ft_strtrim(str, "\t");
		if (ftt_strchr(str, '\t'))
		{
			ft_putstr_fd("Error\n  ->Found tab inside tha map\n", 2);
			exit (1);
		}
		free(str);
		i++;
	}
}
void	only_valid_characters(t_data *data)
{
	int	i;
	int	j;
	char *str;

	i = 0;
	while (data->map_info.map[i])
	{
		str = ft_strdup(data->map_info.map[i]);
		str = ft_strtrim(str, "\t");
		j = 0;
		while (str[j])
		{
			if (str[j] != '1' && str[j] != '0' && str[j] != 'N' && str[j] != ' ' && str[j] != 'S' && str[j] != 'W' && str[j] != 'E')
			{
				ft_putstr_fd("Error\n  ->Found a forbidden character.\n", 2);
				exit (1);
			}
			j++;
		}
		free(str);
		i++;
	}
}

void	check_surr_by_walls(t_data *data)
{
	int	i;
	int len;
	char *str;

	i = 1;
	if (ft_strchr(data->map_info.map[0], '0'))
		not_surr_err();
	while (data->map_info.map[i])
	{
		str = ft_strdup(data->map_info.map[i]);
		str = ft_strtrim(str, "\t");
		len = ftt_strlen(str);
		if (!ft_strncmp(str, "0", 1))
			not_surr_err();
		if (str[len - 1] == '0')
			not_surr_err();
		free(str);
		i++;
	}
	if (ft_strchr(data->map_info.map[i - 1], '0'))
		not_surr_err();
}
void	check_around_spaces(t_data *data)
{
	int i;
	int	j;
	char **str;

	i = 0;
	str = malloc(sizeof(char *) * data->map_info.columns - 6);
	if (!str)
		return ;
	while (data->map_info.map[i])
	{
		str[i] = ft_strtrim(data->map_info.map[i], "\t");
		i++;
	}
	str[i] = NULL;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
			{
				if (str[i - 1][j] != '1' || str[i + 1][j] != '1'
					|| str[i][j - 1] != '1' || str[i][j + 1] != '1')
					around_spaces_err();
			}
			j++;
		}
		i++;
	}
}
void	check_map(t_data *data)
{
	found_tab_inside(data);
	only_valid_characters(data);
	check_surr_by_walls(data);
	check_around_spaces(data);
}
