/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation_tools2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:46:48 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/26 12:17:13 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	exit_from_window(t_data *data)
{
	destroyimage(data);
	exit(0);
	return (0);
}

int	calculatecoin(t_data *data)
{
	int	i;
	int	coin;
	int	j;

	i = 0;
	coin = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				coin++;
			j++;
		}
		i++;
	}
	return (coin);
}

void	handletextures(t_data *data)
{
	if (data->player != NULL)
		mlx_destroy_image(data->mlx, data->player);
	if (data->wall != NULL)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->coin != NULL)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->door != NULL)
		mlx_destroy_image(data->mlx, data->door);
	if (data->dooropen != NULL)
		mlx_destroy_image(data->mlx, data->dooropen);
	if (data->tiles != NULL)
		mlx_destroy_image(data->mlx, data->tiles);
}
