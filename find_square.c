#include "bsq_head.h"

int		is_square(int count, int size)
{
	if (count == size * size)
		return (1);
	return(0);
}

void	increment(int *count, int *y)
{
	*count = *count + 1;
	*y = *y + 1;
}

void	decrement(int *count, int *x)
{
	*count = *count + 1;
	*x = *x - 1;
}

/* 
	Function will test how big square can be drawn on map at given x & y 
	coordinates (top left of square)
*/

int		find_square(char **map, int y_start, int x_start, char o)
{
	int	x;
	int	y;
	int	count;
	int	size;

	x = x_start + 1;
	y = y_start;
	count = 1;
	size = 1;
	while (1)
	{
		while (o == map[y][x] && y < y_start + size && y < g_lines)
			increment(&count, &y);
		if (y == y_start + size)
			while (o == map[y][x] && x >= x_start)
				decrement(&count, &x);
		if (is_square(count, size + 1))
			size++;
		else 
			return (size);
		x = x + size + 1;
		y = y_start;
	}
}