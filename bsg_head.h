#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //DEBUGGING - to remove when finised
#include <fcntl.h>

char	**getMapFile(char *filename, int *lines);
char	**getMapStdIn(int *lines);
int		checkMap(char **map, int lines);
int		check_length(char **map, int y_length);
void	ft_putstr(char *str);
int		check_chars(char **map, int y_length);
int		check_size(char **map, int y_length);
int		find_square(char **map, int y_start, int x_start, char open);
void	solve_squares(char **map, int lines, int width);