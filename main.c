#include "cub3d.h"


/*
I need to be able to draw a line that shoots out in front of the player so I can
see the orientation of the player and when they rotate.
*/
void	ft_rotate_player(void *game)
{
	(void)game;

}


void	loop(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_move_player, game);
	mlx_loop_hook(game->mlx, ft_rotate_player, game);
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


