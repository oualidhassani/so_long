/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:53:01 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/25 23:55:49 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkifthemapbig(t_data *data)
{
	int	x;
	int	y;

	x = 2650;
	y = 1440;
	if (data->height * 64 > y || data->width * 64 > x)
	{
		ft_free1(data->map);
		print_error("error more than the screen");
	}
}

void	destroyimage(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->tiles);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->coin);
	mlx_destroy_image(data->mlx, data->door);
	mlx_destroy_image(data->mlx, data->dooropen);
	mlx_destroy_window(data->mlx, data->win);
}

void	parsingall(int ac, char **av)
{
	t_data	data;

	data.height = 0;
	data.width = 0;
	if (ac > 2 || ac < 2)
		print_error("Error need : ./so_long [map.ber]\n");
	check_dotber(av);
	ft_hieght(&data, av[1]);
	if (map_dyali(&data, av[1]) == 1)
		print_error("Error in map\n");
	ifthemapisvalid(&data);
	check_if_valid_player(&data, 0);
	ft_check(&data);
	check_walls(&data);
	check_walls_helper(&data);
	checkifthemapbig(&data);
	ft_copy(&data);
	flood_fill(&data);
	ft_free(data.map2);
	put_images(&data);
}
