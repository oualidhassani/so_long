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
    if(ac > 2 || ac < 2)
        print_error("Error need : ./so_long [map.ber]\n");
    ft_read_map(&data, av[1]);
    ft_check(&data);
}