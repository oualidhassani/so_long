#include "so_long.h"

void ft_free1(char **str)
{
    int i =0;

    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
int 	ft_strlen1(char *s)
{
	int 	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

void ifthemapisvalid(t_data *data) 
{
    if (!data->map || !data->map[0]) {
        return;
    }

    int len_width = ft_strlen1(data->map[0]);

    int i = 1;
    while (data->map[i] != NULL) {
        int  row_len = ft_strlen1(data->map[i]);
        if (row_len != len_width) 
        {
            print_error("the rows are not the same length\n");
            return;
        }
        i++;
    }
}

void check_walls(t_data *data)
{
    int y;

    y = 0;

    while(data->map[0][y])
    {
        if(data->map[0][y] != '1')
            print_error("Error\n"); 
        y++;  
    }
    y = 0;
    while(data->map[data->height - 1][y])
    {
        if(data->map[data->height- 1][y] != '1')
            print_error("Error\n"); 
        y++;  
    }
}

void check_walls_helper(t_data *data)
{
    int x;

    x = 0;
    while(x < data->height)
    {
        if(data->map[x][0] != '1')
            print_error("Error\n"); 
        x++;  
    }
    x = 0;
    while(x < data->height)
    {
        if(data->map[x][data->width - 1] != '1')
            print_error("Error\n"); 
        x++;  
    }
}

void check_if_valid_player(t_data *data)
{
    int i = 0;
    int flag = 0;
    int flag2 = 0;
    while (data->map[i])
    {
        int j = 0;
        while (data->map[i][j])
        {
            if(data->map[i][j] == 'P')
                flag++;
            if(data->map[i][j] == 'E')
                flag2++;
            j++;
        }        
        i++;
    }
    if(flag != 1 || flag2 != 1)
        print_error("error\n");
}
