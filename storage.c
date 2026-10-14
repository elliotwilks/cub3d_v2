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

/*
I think the problem with this is that each time the function gets called
it uses read and consumes two bites. So I should scan then am then put
them back. At the moment I am collecting the line and then going past the
identifier.

I maybe get next line is not the right function for this. It is taking too
much so I cant get the next identifier.

*/

/*
I should count upto the point I get a newline and then I should take that
number and just copy across everything upto that number.

Wait but then we cant go back or can we? Because we have read upto that point
can we go back?
*/
/*
In order to get each part of the grid correctly. How should I approach this?
How will the .cub file differ each time?

	- The order of the floor, ceiling, north, south, east and west tetures can
	  change so I need to use their "identifiers" and then store the path or
	  information that comes afterwards.

*/
