#include "cub3d.h"

void	get_position(t_player *player, char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'N')
			{
				player->x_position = i;
				player->y_position = j;
			}
			j++;
		}
		i++;
	}
}

void	get_orientation(t_player *player)
{
	player->x_orientation = 0;
	player->y_orientation = 1;
}

t_player	*build_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));

	player->turn_direction = 0;
	player->walk_direction = 0;
	player->move_speed = 2;
	player->rotation_speed = 1;
	player->player_image = mlx_new_image(game->mlx, 33, 33);

	get_position(player, game->data->grid);
	get_orientation(player);

	return (player);
}
