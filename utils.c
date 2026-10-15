#include "cub3d.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		negative = 1;

	if (str[i] == '-' || str[i] == '+')
		i++;

	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (negative == 1)
		return (-result);
	else
		return (result);
}

void	draw_in_image(void *param)
{
	uint32_t	colour;

	colour = 0xEBE01CFF;

	fill_square(param, colour);
}

void	fill_square(void *param, uint32_t colour)
{
	int			x;
	int			y;

	x = 0;
	while (x < PLAYER_SIZE)
	{
		y = 0;
		while (y < PLAYER_SIZE)
		{
			mlx_put_pixel(param, x, y, colour);
			y++;
		}
		x++;
	}
}

int		file_incorrect(char *path)
{
	(void)path;

	return (0);
}

void	handle_error(void)
{
	exit(1);
}

int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	custom_print(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			printf("[\\n]");
		else
			printf("%c", str[i]);
		i++;
	}
	printf("[\\0]");
	printf("\n");
}

int	ft_strlen(const char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (str[i] == '\0')
	{
		buff = malloc(1);
		if (buff == NULL)
			return (NULL);
		buff[i] = '\0';
		return (buff);
	}
	buff = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

void	ft_putstr(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
int	ft_strchr(char *str, char c)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		j;
	int		i;
	char	*buff;
	i = 0;
	j = 0;
	buff = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (buff == NULL)
		return (NULL);

	while (s1[i])
	{
		buff[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		buff[i] = s2[j];
		i++;
		j++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*read_file(int fd, char *storage)
{
	int		bytes;
	char	*buff;
	char	*tmp;

	if (storage == NULL)
		storage = ft_strdup("");
	buff = malloc(BUFFER_SIZE + 1);
	bytes = 1;
	while ((ft_strchr(storage, '\n') == 0) && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buff[bytes] = '\0';
		tmp = storage;
		storage = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	if (!storage || storage[0] == '\0')
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	return (storage);
}

char	*extract_line(char *storage)
{
	int		i;
	int		size;
	char	*line;

	size = 0;
	while (storage[size] && storage[size] != '\n')
		size++;
	if (storage[size] == '\n')
		size++;
	line = malloc(size + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_storage(char *storage, char *line)
{
	int		i;
	int		j;
	char	*new_storage;

	(void)line;
	i = 0;
	j = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	new_storage = malloc(ft_strlen(storage) - i + 1);
	if (!new_storage)
		return (NULL);
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0)
		return (NULL);
	storage = read_file(fd, storage);
	if (storage == NULL)
		return (NULL);
	line = extract_line(storage);
	storage = update_storage(storage, line);
	return (line);
}

void	print_grid(t_data *data)
{
	int		i;

	i = 0;
	while (data->grid[i])
	{
		printf("%s", data->grid[i]);
		i++;
	}
}
