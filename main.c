/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 01:16:01 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int keygenerator(int key_code, t_data *data)
{
	(void)data;
	if (key_code == ESC)	//la brekti ela ESC katkhrej :)
	{
		//+ khas nfreyiw hna again dakxi lakhor kaml before exit..
		exit(0);
	}
	return (0);
}
int	close_window(t_data *data)
{
	(void)data;	//we need it later
	//we need to free all after exit..
	exit (0);
	return (0);
}

void	image_set(t_data *data)
{
	data->map.tex_width = WIDTH;
	data->map.tex_height = HEIGHT;
	data->map.ptr_1_img = mlx_xpm_file_to_image(data->mlx_ptr,
		"elalj/textures/wall.xpm", &data->map.tex_width, &data->map.tex_height);
	data->map.ptr_0_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"elalj/textures/floor.xpm", &data->map.tex_width, &data->map.tex_height);
	data->map.ptr_p_img = mlx_xpm_file_to_image(data->mlx_ptr, "elalj/textures/player.xpm", &data->map.tex_width, &data->map.tex_height);
}
void	put_floor_in_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.str[i])
	{
		j = 0;
		while (data->map.str[i][j])
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map.ptr_0_img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
void	put_images_into_window(t_data *data)
{
	int i = 0;
	int j = 0;
	while (data->map.str[i])
	{
		j = 0;
		while (data->map.str[i][j])
		{
			if (data->map.str[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.ptr_1_img, j * 50, i * 50);
			else if (data->map.str[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->map.ptr_0_img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
void	ft_init_image(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->image.img)
		ft_putstr_fd("Image creation failed\n", 2);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel,
			&data->image.line_length,
			&data->image.endian);
	image_set(data);
	//put_floor_in_window(data);
	put_images_into_window(data);
	mlx_key_hook(data->win_ptr, keygenerator, data);	//keygenerator funcs dyal keys handling...
	mlx_hook(data->win_ptr, 17, 0, close_window, data); //exit button li f window lfo9
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		ft_putstr_fd("Mlx initialization failed\n", 2);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!(data->win_ptr))
		ft_putstr_fd("Window creation failed\n", 2);
	ft_init_image(data);
}

int main(int ac, char **av)
{
	t_data	data;
	int			fd;

	fd = 0;
	if (ac != 2)
		print_and_exit_param(); //error d map beli makynx
	open_fd_check(&fd, av[1]);	//for check ila kan dak map already kayn ->> hadi tal men ba3d wndiroha
	read_map(fd, &data);
	find_cor_player(&data);
	ft_init_data(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
