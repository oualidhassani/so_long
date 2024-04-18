#include "so_long.h"

void put_images(t_data *data)
{
    int width = 0;
    int height = 0;
    void *mlx;
    void *mlx_win;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, data->width * 64,data->height * 64, "so_long");
    void *wall;
    wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &height, &width);
    void *player = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &height, &width);
    //  printf("Value of wall: %p\n", wall);
    int i = 0;
    int j;
      while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if(data->map[i][j] == '1')
                mlx_put_image_to_window(mlx, mlx_win, wall, j * 64, i * 64);
            // else if(data->map[i][j] == '0')
            //     mlx_put_image_to_window(mlx, mlx_win,);
            else if(data->map[i][j] == 'P')
                mlx_put_image_to_window(mlx, mlx_win,player,j * 64,i * 64);
            // else if(data->map[i][j] == 'C')
            //     mlx_put_image_to_window(mlx, mlx_win,);
            j++;
        }
        i++;
    }
    mlx_loop(mlx);
}