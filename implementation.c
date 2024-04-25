/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:46:50 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/25 15:42:47 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int keycode, t_data *data)
{
	if (data->count == 0)
		data->count = 1;
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
	{
		ft_putnbr(data->count++);
		write(1, "\n", 1);
	}
	if (keycode == 13)
		move_up(data);
	if (keycode == 1)
		move_down(data);
	if (keycode == 0)
		move_left(data);
	if (keycode == 2)
		move_right(data);
	if (keycode == 53)
	{
		ft_free1(data->map);
		destroyimage(data);
		exit(0);
	}
	return (0);
}

void	declaration(t_data *data)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &height,
			&width);
	data->player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
			&height, &width);
	data->tiles = mlx_xpm_file_to_image(data->mlx, "textures/tiles.xpm",
			&height, &width);
	data->coin = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm", &height,
			&width);
	data->door = mlx_xpm_file_to_image(data->mlx, "textures/door1.xpm", &height,
			&width);
	data->dooropen = mlx_xpm_file_to_image(data->mlx, "textures/door2.xpm",
			&height, &width);
	if (data->door == NULL || data->player == NULL || data->tiles == NULL
		|| data->coin == NULL || data->dooropen == NULL || data->wall == NULL)
	{
		ft_free1(data->map);
		handletextures(data);
		print_error("Error of texture\n");
	}
}

void	put_the_image_on(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->tiles, j * 64, i * 64);
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 64, i
			* 64);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, j * 64, i
			* 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coin, j * 64, i
			* 64);
	else if (data->map[i][j] == 'E')
	{
		if (calculatecoin(data) == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->dooropen, j
				* 64, i * 64);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->door, j * 64, i
				* 64);
	}
}

void	render_map(t_data *data)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = 64;
	height = 64;
	declaration(data);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_the_image_on(data, i, j);
			j++;
		}
		i++;
	}
}

void	put_images(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width * 64, data->height * 64,
			"so_long");
	render_map(data);
	mlx_key_hook(data->win, &keycode, data);
	mlx_hook(data->win, 17, 0, exit_from_window, data);
	mlx_loop(data->mlx);
}
