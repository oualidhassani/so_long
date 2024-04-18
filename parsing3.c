#include "so_long.h"

void parsingall(int ac, char **av)
{
     t_data data;
    data.height = 0;
    data.width = 0;
    if(ac > 2 || ac < 2)
        print_error("Error need : ./so_long [map.ber]\n");
    check_dotber(av);
    ft_hieght(&data, av[1]);
    if(map_dyali(&data, av[1]) == 1)
        print_error("Error in map\n");
    ifthemapisvalid(&data);
    ft_check(&data);
    check_walls(&data);
    check_walls_helper(&data);
    ft_copy(&data);
    flood_fill(&data);
    print2DArray(data.map ,data.height ,data.width);
     put_images(&data);
    

}