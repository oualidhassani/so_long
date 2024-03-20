#include "so_long.h"

void ft_hieght(t_data *data, char *file)
{
    int fd;
    char *buffer;
    fd = open (file, O_RDONLY);
    if (fd == -1)
    {
        print_error("Error\nfilde file\n");
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
void map_dyali(t_data *data, char *file)
{

        int lenght = data->height;
        char *buffer;
        int fd;
        data->map = (char **)malloc(sizeof(char *) * (lenght  + 1));
        if (data->map == NULL)
            print_error("ERROR\n failed malloc\n");

    fd = open (file, O_RDONLY);
    if (fd == -1)
        print_error("Error\nfilde file\n");
    lenght = 0;
    while (1)
    {
        buffer = get_next_line(fd);
        if (buffer == NULL)
        break;
     data->map[lenght] =  ft_strdup(buffer);
       lenght++;
       free(buffer);
       buffer = NULL;

    }
    data->map[lenght] = 0;
    close(fd);
}
void ft_read_map(t_data *data, char *file)
{
    int i = 0;
       ft_hieght(data, file);
       map_dyali(data, file);
       while (i < data->height)
       {
        printf("%s", data->map[i]);
        i++;
       }
}