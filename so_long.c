#include "so_long.h"
void print_error(char *str)
{
    write(2, str, strlen(str));
}
int main(int ac, char **av)
{
    t_data data;
    if(ac > 2 || ac < 2)
    {
        print_error("Error need : ./so_long [map.ber]\n");
        exit(1);
    }    
      
   ft_read_map(&data, av[1]);
}