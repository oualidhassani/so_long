#include "so_long.h"

void move_up(t_data *data)
{
        t_position player_position = get_player_pos(data);

    if(data->map[player_position.x - 1][player_position.y] != '1' &&  data->map[player_position.x - 1][player_position.y] != 'E')
        {
            data->map[player_position.x][player_position.y] =  '0';
            data->map[player_position.x - 1][player_position.y] = 'P';
            render_map(data);
        }
}

void move_down(t_data *data)
{
        t_position player_position = get_player_pos(data);
        if(data->map[player_position.x + 1][player_position.y] != '1' && data->map[player_position.x + 1][player_position.y] != 'E')
        {
            data->map[player_position.x][player_position.y] =  '0';
            data->map[player_position.x + 1][player_position.y] = 'P';
            render_map(data);
        }
}

void move_left(t_data *data)
{
        t_position player_position = get_player_pos(data);

        if(data->map[player_position.x][player_position.y - 1] != '1' && data->map[player_position.x][player_position.y - 1] != 'E')
        {
            data->map[player_position.x][player_position.y] =  '0';
            data->map[player_position.x][player_position.y - 1] = 'P';
            render_map(data);
        }
}

void move_right(t_data *data)
{
        t_position player_position = get_player_pos(data);

    if(data->map[player_position.x][player_position.y + 1] != '1' && data->map[player_position.x][player_position.y + 1] != 'E')
        {
            data->map[player_position.x][player_position.y] =  '0';
            data->map[player_position.x][player_position.y + 1] = 'P';
            render_map(data);
        }
}