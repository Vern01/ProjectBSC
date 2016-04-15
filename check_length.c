/*
Check that the map lines are all the same length.
*/
int check_length(char **map, int y_length)
{
	int	length;
	int	error;
	int	x;
	int	y;
	
	y = 1;
	error = 1;
	length = first_length(map[0]);
	while(y < y_length)
	{
		x = 0;
		while(map[y][x] != '\n')
			x++;
		if(y != 0 && x != length)
		{
			error = 0;
			break;
		}
		y++;
	}
	if(error == 0)
		return 0;
	else
		return 1;
}
/*
Get's the ref point of length that is required of other lines.
*/
 int first_length(char *line)
 {
	 int	x;
	 
	 x = 0;
	 while(line[x] != '\n')
	 	 x++;
	 return x;
 }