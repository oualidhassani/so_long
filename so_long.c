#include "so_long.h"

size_t mb(char *str)
{
    size_t i = 0;

    while(str[i])
        i++;
    return(i);    
}
void print_error(char *str)
{
    (void)write(2, str, mb(str));
    exit(1);
}
int main(int ac, char **av)
{
    t_data data;
    data.height = 0;
    data.width = 0;
    parsingall(ac, av);

}


// int main(int ac, char **av)
// {
//     t_data data;
//     data.height = 0;
//     data.width = 0;
//     if(ac > 2 || ac < 2)
//         print_error("Error need : ./so_long [map.ber]\n");
//     check_dotber(av);
//     ft_hieght(&data, av[1]);
//     if(map_dyali(&data, av[1]) == 1)
//         print_error("Error in map\n");
//     ifthemapisvalid(&data);
//     ft_check(&data);
//     check_walls(&data);
//     check_walls_helper(&data);
//     ft_copy(&data);
//     flood_fill(&data);
//     print2DArray(data.map ,data.height ,data.width);
//     put_images(&data );

// }