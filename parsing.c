#include "so_long.h"

int 	ft_strlen1(char *s)
{
	int 	c;

	c = 0;
	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}

void ifthemapisvalid(t_data *data) 
{
    if (!data->map || !data->map[0]) {
        return;
    }

    int len_width = ft_strlen1(data->map[0]);
    // int len_height = ft_strlen1(data->map[0]);

    int i = 1;

    while (data->map[i])
    {
        j++;
    }
    while (data->map[i] != NULL) {
        int  row_len = ft_strlen1(data->map[i]);
        if (row_len != len_width) {
            print_error("the rows are not the same length");
            return;
        }
        i++;
    }
}