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
	while (x < 100)
	{
		y = 0;
		while (y < 100)
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

