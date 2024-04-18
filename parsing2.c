#include "so_long.h"

t_position get_player_pos(t_data *data)
{
    int i;
    int j;
    t_position p;

    p.x = 0;
    p.y = 0;
    i = 0;
    while (i < data->height )
    {
        j = 0;
        while (j < data->width)
        {
            if (data->map[i][j] == 'P')
            {
                p.x = i;
                p.y = j;
                return (p);
            }
            j++;
        }
        i++;
    }
    return (p);
}

void print2DArray(char **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void flood_fill_recursive(char **map,int x,int y)
{
    //if l7atyt return map[x][y];

    if (map[x][y] == '1' || map[x][y] == 'X')
        return ;
    if (map[x][y] == 'E')
    {
        map[x][y] = 'X';
        return;
    }
    map[x][y] = 'X';
    flood_fill_recursive(map,x - 1,y);
    flood_fill_recursive(map,x + 1,y);
    flood_fill_recursive(map,x,y - 1);
    flood_fill_recursive(map,x,y + 1);

}

void check_after_flood_fill(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->height )
    {
        j = 0;
        while (j < data->width)
        {
            if (data->map2[i][j] == 'C' || data->map2[i][j] == 'E')
            {
                ft_free1(data->map2);
                print_error("Error Map invalid\n");
            }
            j++;
        }
        i++;
    }
}

void flood_fill(t_data *data)
{

    t_position p;

    p = get_player_pos(data);
    flood_fill_recursive(data->map2,p.x,p.y);
    check_after_flood_fill(data);
}

void check_dotber(char **av)
{
    int len;
    char *str = ".ber";
    len = ft_strlen(av[1]);
        if(len >= 4)
        {
            if(ft_strcmp(av[1] + len - 4, str) != 0)
                print_error("is not the good argument !");
        }
}