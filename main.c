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

	printf("%d\n", fd);

	return (data->grid);
}

int		scan(int fd, char *identifiers)
{
	char	*buff;
	int		i;
	int		j;
	int		count;

	buff = malloc(sizeof(char) * 2);

	read(fd, buff, 2);
	buff[2] = '\0';

	i = 0;
	while (buff[i])
	{
		if (ft_strcmp(buff[i]), identifiers[i] == 0) // if both strings are equal
		i++;
	}

	/*
	If both the characters are not equal to each other then
	*/

	return (buff[1]);
}


/*
In the map.cub file each texture has a path. Each texture has an
identifier. For example: 'NO' <--- Identifier './textures/north_texture' <-- path

So I need to be able to scan each character in the file untill I see the
identifier. Then I need to up everything after the space into the correct variable.
Either a texture type, floor or ceiling

There is 6 of these variables. So I should count each time a variable is added.
Then I know. After 6, everything after that should be the map. Maybe theres
a better what do do this.

Also one thing to consider is, will the stream go back to the start position or will
it go upto the point it has read to/ stay there?

I have forgot how the scan() & consume() functions work.

It should be something along the lines of

int		scan(int fd, char *identifiers)
{

}

if (scan(fd, "NO") == 1)
{
	// read till the newline and put in the string variable
}


*/
void	get_textures(t_data *data, char *path)
{
	int		count;
	int		fd;
	char	buff[33];

	fd = open(path, O_RDONLY);
	count = 0;

	while (1)
	{
		if (scan(fd, "NO") == 1)
			data->north_texture = get_upto_newline(fd);

		else if (scan(fd, "SO") == 1)
			data->south_texture = get_upto_newline(fd);

		else if (scan(fd, "WE") == 1)
			data->west_texture = get_upto_newline(fd);

		else if (scan(fd, "WE") == 1)
			data->east_texture = get_upto_newline(fd);

		///hhhhm this is not really perfect


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
