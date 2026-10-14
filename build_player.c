#include "cub3d.h"

void	print_player(t_player *player)
{
	printf("%d\n", player->x_position);
	printf("%d\n", player->y_position);
}

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

t_player	*build_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));

	player->turn_direction = 0;
	player->walk_direction = 0;
	player->move_speed = 2;
	player->rotation_speed = 1;

	get_position(player, data->grid);

	return (player);
}
