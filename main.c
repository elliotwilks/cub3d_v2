#include "cub3d.h"

/*
:::::::::::::::::::::::::::::	CURRENTLY	 :::::::::::::::::::::::::::::::::::

Goal create a really good mini map. In the mini map I should  be  able  to  move
around, get stopped by a wall and I should be able to see a feild  of  view  and
ray coming out of the player.

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

	game->data->wall = mlx_new_image(game->mlx, 18, 18);

	fill(game->data->wall, 0x32A852FF);

	i = 0;
	while (game->data->grid[i] != NULL)
	{
		j = 0;
		while (game->data->grid[i][j] != '\n' && game->data->grid[i][j] != '\0')
		{
			if (game->data->grid[i][j] == '1')
				mlx_image_to_window(game->mlx, game->data->wall, j * 24, i * 24);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	game->player->player_image = mlx_new_image(game->mlx, 20, 20);

	fill(game->player->player_image, 0x008CE3FF);

	mlx_image_to_window(game->mlx, game->player->player_image, game->player->x_position * 24, game->player->y_position * 24);
}

void ft_move_player(void* param)
{
	t_game	*game;

	game = (t_game *)param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->player->y_position -= SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->player->y_position += SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player->x_position -= SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player->x_position += SPEED;

	game->player->player_image->instances[0].x = game->player->x_position;
	game->player->player_image->instances[0].y = game->player->y_position;
}

void	init(t_game *game, char *argv)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX Window", true);
	game->data = get_data(game->data, argv);
	game->player = build_player(game);
}

void	loop(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_move_player, game);
}

int	main(int argc, char **argv)
{
	t_game			game;

	check_args(argc);

	init(&game, argv[1]);

	draw_mini_map(&game);

	draw_player(&game);

	loop(&game);

	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);

	return (1);
}

/*
::::::::::::::::::::::::::::		TASK		::::::::::::::::::::::::::::::::

From the information I have collected I should now build the mini  map.  Putting
the player in the correct position and moving the player through  the  map  with
the button press hooks. I can than  also  use  the  feild  of  view  and  player
oreintation vector to draw the feild of view lines  and  the  looking  direction
line. After that I should attempt the DDA Algorithum.

Lets first look through the other example structs for the player  and  check  my
struct is holding all the information needed. Then I should check  that  I  have
parsed all the infromation I need for the player and map. After, draw it out.


::::::::::::::::::::::::::		LEARNING		::::::::::::::::::::::::::::::::


--------------    What is a Vector?		-----------------

For 2D a vector is two numbers. For 3D  it  is  three  numbers  or  more.  These
numbers give you an idea of somethings position in space. For example if we have
a 2D map. We need both the x and y coordinates inorder to understand  the  exact
possition of something. So this is what a "vector is".

The word "vector" in terms of mathamatics was created in th 1840s  by  an  Irish
Mathmatician called William Rowan Hamilton. He gave the word vector the meaning:
A number with 4 parts. So its basicly a number that has 2 or 3 or 4 parts to it.
For example (2, 45) for x and y or (23, 33, 21) for x y and z.


STEPS:

1) Get the player orientation
2) Substract FOV / 2 to player orientation
3) Cast a ray traces it until it hits a wall
4) Record the distance between the player and the wall hit
5) Add angle increment (0.001636 rad) to throw the next ray
6) Repeat from step 3 until ray orientation is player orientation + (FOV / 2)

*/
