#include "so_long.h"

void ft_hieght(t_data *data, char *file)
{
    int fd;
    char *buffer;
    fd = open (file, O_RDONLY);
    if (fd == -1)
    {
        print_error("fail the file\n");
        exit(1);
    }
    while (1)
    {
        buffer = get_next_line(fd);
        if(buffer == NULL)
             break;
       data->height++;
       free(buffer);
       buffer = NULL;

    }
    close(fd);
}
int map_dyali(t_data *data, char *file)
{

    int lenght = data->height;
    char *buffer;
    int fd;
    data->map = (char **)malloc(sizeof(char *) * (lenght  + 1));
    if (data->map == NULL)
    {
        print_error("Error\n failed malloc\n");
        exit(1);
    }
    fd = open (file, O_RDONLY);
    if (fd == -1)
    {
        print_error("fail the file\n");
        exit(1);
    }
    lenght = 0;
    while (1)
    {
        buffer = get_next_line(fd);
        if (buffer == NULL)
             break;
        buffer[ft_strlen(buffer) - 1] = '\0';
        data->map[lenght] =  ft_strdup(buffer);
       lenght++;
       free(buffer);
       buffer = NULL;
    }
    if(lenght == 0)
    {
        close(fd);
        return (1);
    }
    data->map[lenght] = 0;
    data->width = ft_strlen(data->map[0]);
    close(fd);
    return (0);
}


void ft_copy(t_data *data)
{
    int i;

    i = 0;
    data->map2 = (char **)malloc(sizeof(char *) *data->height);
    while (i < data->height)
    {
        data->map2[i] = ft_strdup(data->map[i]);
        i++;
    }
    data->map[i] = NULL;
}

void ft_check(t_data *data)
{
    int i = 0;
    int j;

    while(i < data->height)
    {
        j = 0;
        while(j < data->width)
        {
            if(data->map[i][j] != 'C' && data->map[i][j] != 'P' && data->map[i][j] != '0' && data->map[i][j] != 'E' && data->map[i][j] != '1')
                print_error("Error there is a wrong charachter!\n" );
             j++;
        }
        i++;
    }
}

