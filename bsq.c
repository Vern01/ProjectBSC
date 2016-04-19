#include "bsg_head.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		map_width(char **map)
{
	int	i;
	
	i = 0;
	
	while (map[1][i] != '\n')
		i++;
	return (i);
}

void	printMap(char **map, int lines)//for debugging
{
	int	l;

	l = 0;
	while (l <= lines)
		ft_putstr(map[l++]);
	
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
		return (0);		
	}
	else
	{
		while (i <= argv - 1)
		{
			map = getMapFile(argc[i], &lines);
			//printMap(map, lines); //temp
			//write(1, "\nSolution :\n", 12); //temp
			if (checkMap(map, lines))
				solve_squares(map, lines, map_width(map));
			i++;
			freeMap(map, lines);
		}
	}
	return (0);
}