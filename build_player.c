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

/*
Orientation vector? What should my default be?

I want the player to be looking up and straight. So the y should be 1 and the  x
should be 0. These are the defaults. I might have to change this later  but  for
now this is my instinct. I should be able to use this information along with the
feild of veiw and half_of_feild_of_view variables to draw a triangle.
*/
void	get_orientation(t_player *player)
{
	player->x_orientation = 0;
	player->y_orientation = 1;
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
	get_orientation(player);

	return (player);
}
