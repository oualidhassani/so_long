#include "so_long.h"

int main()
{
    void *mlx;
    void *mlx_window;
    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1080, "my maps");

    mlx_loop(mlx_window);
}