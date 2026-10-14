#include "cub3d.h"


int	main(int argc, char **argv)
{
	t_data			*data;
	t_player		*player;
	mlx_t			*mlx;
	mlx_image_t		*image;

	(void)image;
	(void)mlx;

	if (argc != 2)
		return (printf("map file needed\n"), 0);

	data = NULL;
	data = get_data(data, argv[1]);

	player = NULL;
	player = build_player(data);

	print_player(player);

	return (1);
}
