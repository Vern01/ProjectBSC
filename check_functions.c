#include "bsq_head.h"

/*
	Get's the ref point of length that is required of other lines.
*/
 int first_length(char *line)
 {
	 int	x;

	 x = 0;
	 while(line[x] != '\n')
	 	 x++;
	 return x;
 }

 /*
	Check that the map lines are all the same length.
*/
int check_length(char **map, int y_length)
{
	int	length;
	int	x;
	int	y;

	y = 1;
	length = first_length(map[1]);
	while (y <= y_length)
	{
		x = 0;
		while (map[y][x] != '\n')
			x++;
		if (y != 0 && x != length)
			return (0);
		y++;
	}
	return (1);
}

/*
	Check if only given chars are on the map;
*/
int	check_chars(char **map, int y_length)
{
	int 	x;
	int		y;
	char	c;

	y = 1;
	while (y <= y_length)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			c = map[y][x];
			if (c != g_open && c != g_obstacle)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
	Check if map size is ateast 1 
*/
int	check_size(char **map, int y_length)
{
	int	x;

	x = 0;
	if (y_length < 1)
		return (0);
	while (map[1][x] != '\n')
		x++;
	if (x == 0)
		return (0);
	else 
		return(1);
}
