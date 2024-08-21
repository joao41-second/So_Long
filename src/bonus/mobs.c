#include "../so_long.h"

char ft_random(int min,int max)
{
     int nubmer;
     

     nubmer = (rand() % (max - min + 1)) + min;
     if( nubmer >= 50)
     {  
        return('0');
     }

     return('M');

}



char **ger_mob( char **map)
{

	int		x;
	int		y;
  //  t_point size;

	
	y = -1;

	while (map[++y] != NULL)
	{
		x = -1;
		
		while (map[y][++x] != '\0')
		{
			if(map[y][x] == '0')
            {
                map[y][x]= ft_random(49,100);
            }
			
		}
	}
  
    // size.y = y;
	// size.x = ft_strlen(map[0]) - 1;
    // flood_fill(map, size, locat_player(map), "C0EP");
	// if (locat_colt(map, 1) == 0)
	// {
	// 	ger_mob(map); 
	// }
    return(map);
}