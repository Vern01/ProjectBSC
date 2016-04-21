#include "bsq_head.h"

int		map_width(char **map)
{
	int	i;

	i = 0;
	while (map[1][i] != '\n')
		i++;
	return (i);
}

void	freeMap(char **map, int lines)
{
	int	l;

	l = 0;
	while (l <= lines)
		free(map[l++]);
	free(map);
}

int		main(int argv, char** argc)
{
	int		i;
	int		lines;
	char	**map;

	i = 1;
	if (argv - 1 == 0)
	{
		map = getMapStdIn(&lines);
		if (checkMap(map, lines))
				solve_squares(map, lines, map_width(map));	
	}
	else
	{
		while (i <= argv - 1)
		{
			if (open(argc[i], O_RDONLY, 1) != -1)
			{
				map = getMapFile(argc[i], &lines);
				if (checkMap(map, lines))
					solve_squares(map, lines, map_width(map));
				freeMap(map, lines);
			}
			i++;
		}
	}
	return (0);
}