#include "fdf.h"
#include <stdio.h>
//******************//
#include <time.h>
#include <stdlib.h>
//******************//

int	key(int keycode, t_e *mlx)
{
	static double	zoom = 1;
	static double	mul = 1;

	printf("key : %d\n", keycode);
	if (keycode == 12) // (q)uit
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (keycode == 67) // *
		mul = mul * 10;
	else if (keycode == 75) // /
		mul = mul / 10;
	else if (keycode == 69) // +
	{
		zoom = zoom + mul;
		printf("\e[32mIncrement : %f\e[0m\n", zoom);
		draw(mlx, zoom);
	}
	else if (keycode == 78) // -
	{
		zoom = (zoom - mul);
		printf("\e[31mDecrement: %f\e[0m\n", zoom);
		draw(mlx, zoom);
	}
	return(0);
}

int	main(int ac, char **av)
{
	t_e		pos;
	int		t;
	
	srand(time(NULL));
	pos.y = 1;
	pos.out = 1;
	t = 1;
	pos.mlx = mlx_init();
	pos.win = mlx_new_window(pos.mlx, 1000, 1000, "test_42");
	mlx_key_hook(pos.win, key, &pos);
	mlx_loop(pos.mlx);
	return (0);
}
