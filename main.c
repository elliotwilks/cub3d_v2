#include "cub3d.h"



void	get_textures(t_data *data, char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "NO ", 3) == 0)
			data->north_texture = ft_strtrim(line + 3, " \n");
		else if (ft_strncmp(line, "SO ", 3) == 0)
			data->south_texture = ft_strtrim(line + 3, " \n");
		else if (ft_strncmp(line, "WE ", 3) == 0)
			data->west_texture = ft_strtrim(line + 3, " \n");
		else if (ft_strncmp(line, "EA ", 3) == 0)
			data->east_texture = ft_strtrim(line + 3, " \n");
		else if (ft_strncmp(line, "C ", 2) == 0)
			data->ceiling = ft_strtrim(line + 3, " \n");
		else if (ft_strncmp(line, "F ", 2) == 0)
			data->floor = ft_strtrim(line + 3, " \n");
		else
		{
			free(line);
			continue ;
		}
		free(line);
		count++;
	}
}

char	**get_grid(t_data *data, char *path)
{
	int		fd;

	(void)data;

	fd = open(path, O_RDONLY);

	printf("File Descriptor for map.cub is: %d\n", fd);

	return (data->grid);
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
