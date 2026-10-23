#include "cub3d.h"

/*
:::::::::::::::::::::::::		CURRENTLY	   :::::::::::::::::::::::::::::::::


*/

static void	fill(mlx_image_t *img, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_game *game)
{
	int		i;
	int		j;

	game->data->wall = mlx_new_image(game->mlx, WALL_BLOCK_SIZE, WALL_BLOCK_SIZE);

	fill(game->data->wall, 0x32A852FF);

	i = 0;
	while (game->data->grid[i] != NULL)
	{
		j = 0;
		while (game->data->grid[i][j] != '\n' && game->data->grid[i][j] != '\0')
		{
			if (game->data->grid[i][j] == '1')
				mlx_image_to_window(game->mlx, game->data->wall, j * WALL_BLOCK_SIZE, i * WALL_BLOCK_SIZE);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	game->player->player_image = mlx_new_image(game->mlx, PLAYER_SIZE, PLAYER_SIZE);

	fill(game->player->player_image, 0x008CE3FF);

	mlx_image_to_window(game->mlx, game->player->player_image, game->player->x_position, game->player->y_position);
}



/*
Breaking this funciton down.

Function returns 1 if the coordinates are hitting a wall and
zero if it is not.

*/
int	is_wall(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	(void)game;

	x = new_x / WALL_BLOCK_SIZE;
	y = new_y / WALL_BLOCK_SIZE;

	if (x < 0 || y < 0)
		return (1);

	return (0);
}

void ft_move_player(void* param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;

	new_x = game->player->x_position;
	new_y = game->player->y_position;

	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		new_y -= SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		new_y += SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		new_x -= SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		new_x += SPEED;

	// If the new x and y coordinates move into a wall then set to the old coordinates
	if (is_wall(game, new_x, new_y) == 1)
	{
		game->player->player_image->instances[0].x = game->player->x_position;
		game->player->player_image->instances[0].y = game->player->y_position;
	}
	else
	{
		game->player->x_position = new_x;
		game->player->y_position = new_y;
		game->player->player_image->instances[0].x = new_x;
		game->player->player_image->instances[0].y = new_y;
	}
}

void	loop(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_move_player, game);
}



int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc);

	init(&game, argv[1]);

	draw_mini_map(&game);

	draw_player(&game);

	loop(&game);

	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);

	return (1);
}


