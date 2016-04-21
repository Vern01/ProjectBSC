#ifndef BSQ
# define BSQ
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	**getMapFile(char *filename, int *lines);
char	**getMapStdIn(int *lines);
int		checkMap(char **map, int lines);
int		check_length(char **map, int y_length);
int		check_chars(char **map, int y_length);
int		check_size(char **map, int y_length);
int		find_square(char **map, int y_start, int x_start, char open);
void	solve_squares(char **map, int lines, int width);
char	g_open;
char	g_obstacle;
char	g_full;
char	g_lines;

#endif