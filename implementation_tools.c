/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:31:22 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/21 12:46:18 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	t_position	player_position;

	player_position = get_player_pos(data);
	if (data->map[player_position.x - 1][player_position.y] != '1'
		&& data->map[player_position.x - 1][player_position.y] != 'E')
	{
		data->map[player_position.x][player_position.y] = '0';
		data->map[player_position.x - 1][player_position.y] = 'P';
		render_map(data);
	}
	if (calculatecoin(data) == 0 && data->map[player_position.x
		- 1][player_position.y] == 'E')
	{
		ft_free1(data->map);
		destroyimage(data);
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
}

void	move_down(t_data *data)
{
	t_position	player_position;

	player_position = get_player_pos(data);
	if (data->map[player_position.x + 1][player_position.y] != '1'
		&& data->map[player_position.x + 1][player_position.y] != 'E')
	{
		data->map[player_position.x][player_position.y] = '0';
		data->map[player_position.x + 1][player_position.y] = 'P';
		render_map(data);
	}
	if (calculatecoin(data) == 0 && data->map[player_position.x
		+ 1][player_position.y] == 'E')
	{
		ft_free1(data->map);
		destroyimage(data);
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
}

void	move_left(t_data *data)
{
	t_position	player_position;

	player_position = get_player_pos(data);
	if (data->map[player_position.x][player_position.y - 1] != '1'
		&& data->map[player_position.x][player_position.y - 1] != 'E')
	{
		data->map[player_position.x][player_position.y] = '0';
		data->map[player_position.x][player_position.y - 1] = 'P';
		render_map(data);
	}
	if (calculatecoin(data) == 0
		&& data->map[player_position.x][player_position.y - 1] == 'E')
	{
		ft_free1(data->map);
		destroyimage(data);
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
}

void	move_right(t_data *data)
{
	t_position	player_position;

	player_position = get_player_pos(data);
	if (data->map[player_position.x][player_position.y + 1] != '1'
		&& data->map[player_position.x][player_position.y + 1] != 'E')
	{
		data->map[player_position.x][player_position.y] = '0';
		data->map[player_position.x][player_position.y + 1] = 'P';
		render_map(data);
	}
	if (calculatecoin(data) == 0
		&& data->map[player_position.x][player_position.y + 1] == 'E')
	{
		ft_free1(data->map);
		destroyimage(data);
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
}
