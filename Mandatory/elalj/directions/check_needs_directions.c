/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_needs_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:02:11 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/10 00:07:13 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_no_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.no[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
	data->text.tex_no = mlx_load_png(data->dir.no[1]);
	if (!data->text.tex_no)
	{
		ft_putstr_fd("Error:  ->Did not found the NO path\n", 2);
		exit (1);
	}
}

void	check_so_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.so[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
	data->text.tex_so = mlx_load_png(data->dir.so[1]);
	if (data->text.tex_so == NULL)
	{
		ft_putstr_fd("Error:  ->Did not found the SO path\n", 2);
		exit (1);
	}
}

void	check_we_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.we[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
	data->text.tex_we = mlx_load_png(data->dir.we[1]);
	if (!data->text.tex_we)
	{
		ft_putstr_fd("Error:  ->Did not found the WE path\n", 2);
		exit (1);
	}
}

void	check_ea_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.ea[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
	data->text.tex_ea = mlx_load_png(data->dir.ea[1]);
	if (!data->text.tex_ea)
	{
		ft_putstr_fd("Error:  ->Did not found the EA path\n", 2);
		exit (1);
	}
}

void	check_f_needs(t_data *data)
{
	int	i;

	i = 0;
	while (data->dir.f[i])
		i++;
	if (i != 2)
		print_err_needs_directions();
}
