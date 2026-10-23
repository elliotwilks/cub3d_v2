#include "cub3d.h"

void	init(t_game *game, char *argv)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX Window", true);
	game->data = get_data(game->data, argv);
	game->player = build_player(game);
}

