/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_needs_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:02:11 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/11 18:02:12 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_NO_n(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.NO[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}
void	check_SO_n(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.SO[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}
void	check_WE_n(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.WE[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}
void	check_EA_n(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.EA[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}

void	check_F_n(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.F[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}

void	check_C_n(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dir.C[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
	j = 0;
	while(data->dir.C[1][i])
	{
		if (data->dir.C[1][i] == ',')
			j++;
		i++;
	}
	if (j != 2)
	{
		ft_putstr_fd("found more/less semicolons", 2);
		exit (1);
	}
}
