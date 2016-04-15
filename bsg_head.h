#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //DEBUGGING - to remove when finised
#include <fcntl.h>

char	**getMapFile(char *filename, int *lines);
char	**getMapStdIn(int *lines);