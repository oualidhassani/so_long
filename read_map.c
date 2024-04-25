/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:54:04 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/25 17:58:53 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hieght(t_data *data, char *file)
{
	int		fd;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("fail the file\n");
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		data->height++;
		free(buffer);
		buffer = NULL;
	}
	close(fd);
}

int	map_dyali(t_data *data, char *file)
{
	int		lenght;
	char	*buffer;
	int		fd;

	lenght = data->height;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("fail the file\n");
	data->map = (char **)malloc(sizeof(char *) * (lenght + 1));
	if (data->map == NULL)
	{
		close(fd);
		ft_free1(data->map);
		print_error("failed malloc\n");
	}
	lenght = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		if (buffer[ft_strlen(buffer) - 1] == '\n')
			buffer[ft_strlen(buffer) - 1] = '\0';
		data->map[lenght] = ft_strdup(buffer);
		lenght++;
		free(buffer);
		buffer = NULL;
	}
	if (lenght == 0)
	{
		close(fd);
		return (1);
	}
	data->map[lenght] = 0;
	data->width = ft_strlen(data->map[0]);
	close(fd);
	return (0);
}

void	ft_copy(t_data *data)
{
	int	i;
	int	length;
	int	j;

	i = 0;
	length = data->height;
	data->map2 = (char **)malloc(sizeof(char *) * (length + 1));
	if (data->map2 == NULL)
		return ;
	while (i < data->height)
	{
		data->map2[i] = ft_strdup(data->map[i]);
		if (data->map2[i] == NULL)
		{
			j = 0;
			while (i > j)
			{
				ft_free1(data->map2);
				j++;
			}
		}
		i++;
	}
	data->map2[i] = NULL;
}

void	ft_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] != 'C' && data->map[i][j] != 'P'
				&& data->map[i][j] != '0' && data->map[i][j] != 'E'
				&& data->map[i][j] != '1')
			{
				ft_free1(data->map);
				print_error("Error there is a wrong charachter!\n");
			}
			j++;
		}
		i++;
	}
}
