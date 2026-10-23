#include "cub3d.h"

void	fill(mlx_image_t *img, uint32_t color)
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
