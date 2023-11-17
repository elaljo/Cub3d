/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:11:46 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/16 16:53:40 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_f(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "F", 1))
			data->dir.F = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}

void	ft_c(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(data->map_info.str[i], "C", 1))
			data->dir.C = ftt_split(data->map_info.str[i], ' ');
		i++;
	}
}

void	check_valid_directions(t_data *data)
{
	data->c = 0;
	if (!ft_strcmp(data->dir.NO[0], "NO"))
		data->c++;
	else if (!ft_strcmp(data->dir.SO[0], "SO"))
		data->c++;
	else if (!ft_strcmp(data->dir.WE[0], "WE"))
		data->c++;
	else if (!ft_strcmp(data->dir.EA[0], "EA"))
		data->c++;
	else if (!ft_strcmp(data->dir.F[0], "F"))
		data->c++;
	else if (!ft_strcmp(data->dir.C[0], "C"))
		data->c++;
	if (data->c != 6)
		print_err_directions();
}

void	check_directions_needs(t_data *data)
{
	check_no_needs(data);
	check_so_needs(data);
	check_we_needs(data);
	check_ea_needs(data);
	check_f_needs(data);
	check_c_needs(data);
}

void	check_colors(t_data *data)
{
	check_f_c(data);
	check_c_c(data);
}
