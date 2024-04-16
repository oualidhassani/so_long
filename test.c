#include <unistd.h>

void ft_putchar(char *c)
{
    int i = 0;
    while(c[i])
    {
        write(1, &c[i], 1);
        i++;
    }
}

int main()
{
    char c[] = "nta zml";

    ft_putchar(c);
}