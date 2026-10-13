#include "cub3d.h"

/*
In order to get each part of the grid correctly. How should I approach this?
How will the .cub file differ each time?

	- The order of the floor, ceiling, north, south, east and west tetures can
	  change so I need to use their "identifiers" and then store the path or
	  information that comes afterwards.

*/
char	**get_grid(t_data *data, char *path)
{
	int		fd;

	(void)data;

	fd = open(path, O_RDONLY);

	printf("File Descriptor for map.cub is: %d\n", fd);

	return (data->grid);
}

int		scan(int fd, char *identifiers)
{
	char	*buff;

	buff = malloc(sizeof(char) * 2);
	buff[2] = '\0';
	read(fd, buff, 2);

	if (ft_strcmp(buff, identifiers) == 0) // The same as eachother 
		return (1);

	return (0);
}

void	get_textures(t_data *data, char *path)
{
	int		count;
	int		fd;

	fd = open(path, O_RDONLY);

	count = 0;
	while (count < 6) // Six variables to collect
	{
		if (scan(fd, "NO") == 1)
			data->north_texture = get_next_line(fd);

		else if (scan(fd, "SO") == 1)
			data->south_texture = get_next_line(fd);

		else if (scan(fd, "WE") == 1)
			data->west_texture = get_next_line(fd);

		else if (scan(fd, "EA") == 1)
			data->east_texture = get_next_line(fd);

		count++;
	}
}

t_data	*get_data(t_data *data, char *path)
{
	if (file_incorrect(path))
		handle_error();

	data = malloc(sizeof(t_data));

	get_textures(data, path);

	data->grid = get_grid(data, path);

	return (data);
}

int	main(int argc, char **argv)
{
	t_data			*data;
	t_player		*player;
	mlx_t			*mlx;
	mlx_image_t		*image;

	(void)image;
	(void)mlx;
	(void)player;

	if (argc != 2)
		return (printf("map file needed\n"), 0);

	data = NULL;
	data = get_data(data, argv[1]);

	return (1);
}
