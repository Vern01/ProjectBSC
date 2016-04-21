#include "bsq_head.h"

void	set_chars(char **map, int x)
{
	int	i;
	int	j;

	i = x;
	j = 0;
	while (map[0][i++] != '\n')
		j++;
	if (j == 3)
	{
		g_open = map[0][x];
		g_obstacle = map[0][x + 1];
		g_full = map[0][x + 2];
	}
}

/*
	Gets amount of lines given by map & sets global variables
*/
int		get_lines(char **map)
{
	int		i;
	char	num[9];
	int		lines_g;
	int		t;

	i = 0;
	t = 1;
	lines_g = 0;
	while (map[0][i] >= '0' && map [0][i] <= '9')
	{
		num[i] = map[0][i];
		i++;
	}
	if (i > 0 && map[0][i] != '\n')
		set_chars(map, i);
	while (i > 0)
	{
		lines_g += (num[i - 1] - '0') * t;
		t = t * 10;
		i--;
	}
	return (lines_g);
}

int		map_error(void)
{
	write(1, "map error\n", 10);
	return (0);
}

int		checkMap(char **map, int lines)
{
	if (check_length(map, lines) == 0)
		return (map_error());
	g_lines = get_lines(map);
	if (lines != g_lines)
		return (map_error());
	if (check_chars(map, lines) == 0)
		return (map_error());
	if (check_size(map, lines) == 0)
		return (map_error());
	return (1);
}