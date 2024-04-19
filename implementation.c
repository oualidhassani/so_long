#include "so_long.h"
int  keycode(int keycode, t_data *data)
{
    printf("%d\n",keycode);

    if(keycode == 13)
        move_up(data);
    if (keycode == 1)
        move_down(data);
    if (keycode == 0)
        move_left(data);     
    if (keycode == 2)
        move_right(data);
    if(keycode == 53)
        exit(1);        
    return(0);
}

void    render_map(t_data *data)
{
    int width = 64;
    int height = 64;
    void *wall;
    wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &height, &width);
    void *player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &height, &width);
    void *tiles = mlx_xpm_file_to_image(data->mlx, "textures/tiles.xpm", &height, &width);
    void *coin = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm", &height, &width);
    void *door = mlx_xpm_file_to_image(data->mlx, "textures/door1.xpm", &height,&width);
      int i = 0;
    int j;
      while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            mlx_put_image_to_window(data->mlx, data->win,tiles, j * 64, i *64);
            if(data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, wall, j * 64, i * 64);
            else if(data->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win,player,j * 64,i * 64);
            else if(data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win,coin, j * 64, i * 64);
            else if(data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win,door, j * 64, i * 64);
            j++;
        }
        i++;
    }
}
void put_images(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->width * 64,data->height * 64, "so_long");
    render_map(data);
    //  printf("Value of tiles: %p\n", tiles);
    //  printf("Value of coins: %p\n", coin);
    //  printf("Value of door: %p\n", door);

  
    mlx_key_hook(data->win, &keycode,data);
    mlx_loop(data->mlx);
}