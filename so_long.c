#include "so_long.h"
void print_error(char *str)
{
    write(2, str, strlen(str));
}
int main(int ac, char **av)
{
    t_data data;
    if(ac > 2 || ac < 2)
        print_error("./so_long [map.ber]\n");
      
   ft_read_map(&data, av[1]);
}