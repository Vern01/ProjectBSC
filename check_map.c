#include "bsg_head.h"

int		checkMap(char **map, int lines)
{
	int	error;
	int	lines_g;

	error = 1;
	if (check_length(map, lines) == 0)
		error = 0;
	lines_g = map[0][0] - '0';
	if (lines != lines_g) //lines correspond with map info
		error = 0;
	
	if (check_chars(map, lines) == 0)
		error = 0;
	
	if (check_size(map, lines) == 0)
		error = 0;
	
	/*
	
	Other checks ?? 
	
	*/
	if (error == 0)
		ft_putstr("map error\n");
	return (error);
}