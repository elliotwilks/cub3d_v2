/*
	mlx = mlx_init(WIDTH, HEIGHT, "MLX Window", true);
	image = mlx_new_image(mlx, 100, 100);
	mlx_image_to_window(mlx, image, 33, 33);
	mlx_loop_hook(mlx, draw_in_image, image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
*/


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