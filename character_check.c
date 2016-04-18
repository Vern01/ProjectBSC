/*
Checks for invalid characters. I am looking for first mistake so I can cute the search when I find a mistake(saves time).
*/
int characterCheck(char **map, char *ch, int len)
{
	int	x;
	int	y;
	int	test;
		
	y = 0;
	test = 0;
	while(y < len)
	{
		x = 0;
		while(map[y][x] != '\n')
		{
			if(map[y][x] != ch[0] || map[y][x] != ch[1] || map[y][x] != ch[2])
			{
				test = 1;
				break;
			}
			x++;
		}
		if(test == 1)
			break;
		y++;
	}
	return test;
}