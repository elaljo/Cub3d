/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:57:39 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/11 20:57:40 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_C_c(t_data *data)
{
	check_consecutive_semicolon_c(data);
	data->dir.clr_c = ftt_split(data->dir.C[1], ',');
	valid_box_color_c(data);
	valid_color_c(data);
}

void	check_consecutive_semicolon_c(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.C[1][i])
	{
		if (data->dir.C[1][i] == ',')
		{
			i++;
			if(data->dir.C[1][i] == ',')
			{
				ft_putstr_fd("Error: found(,)near to itself", 2);
				exit (1);
			}
		}
		i++;
	}
}
void	valid_box_color_c(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.clr_c[i])
		i++;
	if (i != 3)
	{
		ft_putstr_fd("Error: less/more box colors\n", 2);
		ft_putstr_fd("Usage: Please enter a valid box of colors [..],[..],[..]", 2);
		exit (1);
	}
}
void	valid_color_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dir.clr_c[i])
	{
		if (ft_atoi(data->dir.clr_c[i]) > 255)
		{
			ft_putstr_fd("Please enter a number between 0 and 255", 2);
			exit (1);
		}
		j = 0;
		while (data->dir.clr_c[i][j])
		{
			if (!ft_isdigit(data->dir.clr_c[i][j]))
			{
				ft_putstr_fd("Error: found character in one of boxes", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
}