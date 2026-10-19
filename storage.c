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
/*
This should be easier because we are looking for the start of the map (so either
a 1 or a 0) and then we are using get_next_line() to grab each line of the  map.
data->grid is an array of strings. data->grid[0] is  the  first  string  and  so
on... I should go upto the point

I need to count the number of lines in the grid so I can create the memory space
for the correct amount of lines.

Turns out the best way to do it is to close the file descriptor and then re-open
it so I get a fresh stream to work with.

So the first file descriptor will be used to count the number of lines in the grid
and the second file descriptor will be to fill those lines but in the data->grid
array.

*/
/*

void	print_player(t_player *player)
{
	printf("%d\n", player->x_position);
	printf("%d\n", player->y_position);
}
*/
/******************************************************************************
	Orientation:

	How can I figure this out? What numbers do I have to  work  with?  What  is  my
	range of numbers? Work on this.

	Learning

	Understanding Orientation Coordinates:

	X
	+1 to -1 : Left & Right

	Y
	+1 to -1 : Up & Down





	******************************************************************************/
/*
Orientation vector? What should my default be?

I want the player to be looking up and straight. So the y should be 1 and the  x
should be 0. These are the defaults. I might have to change this later  but  for
now this is my instinct. I should be able to use this information along with the
feild of veiw and half_of_feild_of_view variables to draw a triangle.

I want to improve the following  in  my  program  as  it  should  make  it  more
organised and easeir to work with. Also I want to check if the things I have  in
mind are common pratice or not? My first idea is moving the global varaibles.  I
have heard its bad practice to use global variables so I want to know is there a
better way to use the mlx_image_t *var variables? Maybe I should but them  in  a
struct?

Next I want to have one main game struct that  has  pointer  to  all  the  other
structs in my program. This is mainly so I can parse all the data  I  have  into
the mlx functions. Most of the mlx functions only allow  for  one  thing  to  be
parsed. By having this main/ majour struct I can parse a single thing  but  have
all of my data accessable. I also want to become more familiar  with  instances.
What they do and how they work. Also the meaning behind the word.

*/
