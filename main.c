#include "cub3d.h"

void	draw_mini_map(t_data *data, t_player *player, mlx_t *mlx)
{
	mlx_image_t		*image;

	(void)data;
	(void)player;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX Window", true);
	image = mlx_new_image(mlx, 333, 333);
	mlx_image_to_window(mlx, image, 333, 333);




	mlx_loop_hook(mlx, draw_in_image, image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	main(int argc, char **argv)
{
	t_data			*data;
	t_player		*player;
	mlx_t			*mlx;

	if (argc != 2)
		return (printf("map file needed\n"), 0);

	data = NULL;
	data = get_data(data, argv[1]);

	player = NULL;
	player = build_player(data);

	mlx = NULL;
	draw_mini_map(data, player, mlx);

	return (1);
}

/*
::::::::::::::::::::::::::::		TASK		::::::::::::::::::::::::::::::::

From the information I have collected I should now build the mini  map.  Putting
the player in the correct position and moving the player through  the  map  with
the button press hooks. I can than  also  use  the  feild  of  view  and  player
oreintation vector to draw the feild of view lines  and  the  looking  direction
line. After that I should attempt the DDA Algorithum.

Lets first look through the other example structs for the player  and  check  my
struct is holding all the information needed. Then I should check  that  I  have
parsed all the infromation I need for the player and map. After, draw it out.


::::::::::::::::::::::::::		LEARNING		::::::::::::::::::::::::::::::::


--------------    What is a Vector?		-----------------

For 2D a vector is two numbers. For 3D  it  is  three  numbers  or  more.  These
numbers give you an idea of somethings position in space. For example if we have
a 2D map. We need both the x and y coordinates inorder to understand  the  exact
possition of something. So this is what a "vector is".

The word "vector" in terms of mathamatics was created in th 1840s  by  an  Irish
Mathmatician called William Rowan Hamilton. He gave the word vector the meaning:
A number with 4 parts. So its basicly a number that has 2 or 3 or 4 parts to it.
For example (2, 45) for x and y or (23, 33, 21) for x y and z.


STEPS:

1) Get the player orientation
2) Substract FOV / 2 to player orientation
3) Cast a ray traces it until it hits a wall
4) Record the distance between the player and the wall hit
5) Add angle increment (0.001636 rad) to throw the next ray
6) Repeat from step 3 until ray orientation is player orientation + (FOV / 2)

*/
