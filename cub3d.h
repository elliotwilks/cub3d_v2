# ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include "MLX42.h"
#include "MLX42_Int.h"

#define WIDTH 500
#define HEIGHT 500
#define BUFFER_SIZE 33

typedef struct s_data
{
	char	**grid;
	int		grid_x_max;
	int		grid_y_max;
	int		line_count;

	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
}
t_data;

typedef struct s_player
{
	int		x_position;
	int		y_position;
	int		x_orientation;
	int		y_orientation;
}
t_player;


/*:::::::::::::::::::		UTLIS		:::::::::::::::::::::*/

int		ft_atoi(const char *str);
void	draw_in_image(void *param);
void	fill_square(void *param, uint32_t colour);
int		file_incorrect(char *path);
void	handle_error(void);
int		ft_strcmp(char *s1, char *s2);
void	custom_print(char *str);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void	ft_putstr(char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*read_file(int fd, char *storage);
char	*extract_line(char *storage);
char	*update_storage(char *storage, char *line);
char	*get_next_line(int fd);


#endif //CUB3D_H
