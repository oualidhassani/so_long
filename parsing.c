/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:48:59 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/25 16:08:57 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free1(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ifthemapisvalid(t_data *data)
{
	int	len_width;
	int	i;
	int	row_len;

	if (!data->map || !data->map[0])
	{
		return ;
	}
	len_width = ft_strlen1(data->map[0]);
	i = 1;
	while (data->map[i] != NULL)
	{
		row_len = ft_strlen1(data->map[i]);
		if (row_len != len_width)
		{
			ft_free1(data->map);
			print_error("the rows are not the same length\n");
			return ;
		}
		i++;
	}
}

void	check_walls(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[0][y])
	{
		if (data->map[0][y] != '1')
		{
			ft_free1(data->map);
			print_error("Error\n");
		}
		y++;
	}
	y = 0;
	while (data->map[data->height - 1][y])
	{
		if (data->map[data->height - 1][y] != '1')
		{
			ft_free1(data->map);
			print_error("Error\n");
		}
		y++;
	}
}

void	check_walls_helper(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->height)
	{
		if (data->map[x][0] != '1')
		{
			ft_free1(data->map);
			print_error("Error\n");
		}
		x++;
	}
	x = 0;
	while (x < data->height)
	{
		if (data->map[x][data->width - 1] != '1')
		{
			ft_free1(data->map);
			print_error("Error\n");
		}
		x++;
	}
}

void	check_if_valid_player(t_data *data)
{
	int	i;
	int	flag;
	int	flag2;
	int	j;

	i = 0;
	flag = 0;
	flag2 = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				flag++;
			if (data->map[i][j] == 'E')
				flag2++;
			j++;
		}
		i++;
	}
	if (flag != 1 || flag2 != 1)
	{
		ft_free1(data->map);
		print_error("error there is no exit or player\n");
	}
}
