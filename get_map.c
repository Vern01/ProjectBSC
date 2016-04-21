#include "bsq_head.h"
/*
	Functions to retrieve map and save into char** array 
	note that \n characters and \0 is also saved into array
*/

int		countLines(char *buffer, int size)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			lines++;
		i++;
	
	}
	return (lines);
}

int		lineLength(char *buffer, int pos, int size)
{
	int	i;
	int	linelen;

	i = pos;
	linelen = 0;
	while (buffer[i] != '\n' && i < size)
	{
			linelen++;
			i++;
	}
	return (linelen);
}

char	**createArray(char *buffer, int size, int lines)
{
	int		linelen;
	int		r;
	int		c;
	int		i;
	char	**map;

	i = 0;
	r = 0;
	map = (char**)malloc(lines * sizeof(char*));
	while (r <= countLines(buffer, size) && i < size)
	{
		linelen = lineLength(buffer, i , size) + 1;
		c = 0;
		map[r] = (char*)malloc((linelen + 1) * sizeof(char));
		while (c < linelen)
			map[r][c++] = buffer[i++];
		map[r][c] = '\0';
		r++;
	}
	return (map);
}

char	**getMapFile(char *fileName, int *lines)
{
	char	buffer[4096];
	int		file;
	int		size;

	file = open(fileName, O_RDONLY, 1);
	size = read(file, buffer, 4096);
	buffer[size] = '\n';
	buffer[size + 1] = '\0';
	close(file);
	*lines = countLines(buffer, size);
	return (createArray(buffer, size, *lines));
}

char	**getMapStdIn(int *lines)
{
	char	buffer[4096];
	int		size;

	size = read(0, buffer, 4096);
	buffer[size] = '\n';
	buffer[size + 1] = '\0';
	*lines = countLines(buffer, size);
	return (createArray(buffer, size, *lines));
}