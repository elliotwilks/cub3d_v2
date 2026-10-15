#include "cub3d.h"

int	get_textures(t_data *data, char *path)
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
	return (fd);
}

int		count_lines(int fd)
{
	char	*line;
	int		line_count;

	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strchr(line, '1') || ft_strchr(line, '0' || ft_strchr(line, 'N'))) // if the line contains any of these
		{
			line_count++;
		}
	}
	return (line_count);
}

int		is_map_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;

	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

char	**get_grid(t_data *data, char *path, int fd_parsed)
{
	char	*line;
	int		fd_new;
	int		i;

	(void)path;

	data->line_count = count_lines(fd_parsed);
	close(fd_parsed);

	data->grid = malloc(sizeof(char *) * data->line_count);
	fd_new = open(path, O_RDONLY);

	line = get_next_line(fd_new);
	while (line != NULL && is_map_line(line) != 1)
	{
		free(line);
		line = get_next_line(fd_new);
	}

	i = 0;
	while (line != NULL)
	{
		if (ft_strchr(line, '0') == 1 || ft_strchr(line, '1') == 1)
		{
			data->grid[i] = ft_strdup(line);
		}
		i++;
		line = get_next_line(fd_new);
	}
	data->grid[i] = NULL;

	return (data->grid);
}

// I need to get the longest side for the left and right (x axis)
// So I just move through the grid and then if the
void	get_grid_info(t_data *data)
{
	int		i;
	int		j;
	int		max_length;

	data->grid_y_max = data->line_count;

	i = 0;
	max_length = 0;
	while (data->grid[i])
	{
		j = 0;
		while (data->grid[i][j])
		{
			j++;
			if (j > max_length)
				max_length = j - 1;
		}
		i++;
	}
	data->grid_x_max = max_length;
}

t_data	*get_data(t_data *data, char *path)
{
	int		fd;

	if (file_incorrect(path))
		handle_error();

	data = malloc(sizeof(t_data));

	fd = get_textures(data, path);

	data->grid = get_grid(data, path, fd);

	get_grid_info(data);

	return (data);
}
