#include "bsq_head.h"

int 	g_sol_x = 0;
int		g_sol_y = 1;
int		g_sol_size = 0;

void	print_solved_map(char **map, int p_y, int p_x , int size)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (y <= g_lines)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (y >= p_y && y < p_y + size && x >= p_x && x < p_x + size)
				write(1, &g_full, 1);
			else
				write(1, &map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

/*
	Function will do a few checks to determine wheter find_square function should 
	be called or skipped for certain cases to improve performance
*/
int		should_find_square(char **map, int y, int x, int width)
{
	int	lines;

	lines = map[0][0] - '0';
	if (x >= width - g_sol_size)
		return (0);
	if (y >= g_lines - g_sol_size)
		return (0);
	return (1);
}

void	new_solution(int y, int x, int size)
{
	g_sol_size = size;
	g_sol_y = y;
	g_sol_x = x;
}

void	reset(void)
{
	g_sol_x = 0;
	g_sol_y = 1;
	g_sol_size = 0;
	g_full = '\0';
	g_open = '\0';
	g_obstacle = '\0';
	g_lines = 0;
}
void	solve_squares(char **map, int lines, int width)
{
	int	y; 
	int	x;
	int	size;

	y = 1;
	while (y < lines)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] == g_open)
			{
				if (should_find_square(map, y, x, width))
					size = find_square(map, y, x, g_open);
				if (size > g_sol_size)
					new_solution(y, x, size);
			}
			x++;
		}
		y++;
	}
	print_solved_map(map, g_sol_y, g_sol_x, g_sol_size);
	reset();
}