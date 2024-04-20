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
    write(2, str, mb(str));
    exit(1);
}
int main(int ac, char **av)
{
    parsingall(ac, av);
}
