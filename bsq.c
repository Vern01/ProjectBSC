#include "bsq_head.h"

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

void	printMap(char **map, int lines)
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
	int		maps;
	int		i;
	int		lines;
	char	**map;

	i = 1;
	maps = argv - 1;
	if (maps == 0)
	{
		map = getMapStdIn(&lines);
		//if (checkMap(char **map));//check if valid return 1 if no errors found
		//		solveSquares(argc[i]); //will solve map and output solution
		return (0);		
	}
	else
	{
		while (i <= maps)
		{
			map = getMapFile(argc[i], &lines); // save map into 2D array from file
			if (checkMap(map, lines)) //return 1 if no errors found
				//solveSquares(argc[i]);will solve map and output solution
			printMap(map, lines); //will move inro solve function
			i++;
			freeMap(map, lines);
		}
	}
	return (0);
}