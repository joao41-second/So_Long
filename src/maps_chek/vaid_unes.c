#include "../so_long.h"


int valid_lines(char **map,int len)
{
	int i;
	int size;

	size = ft_strlen(map[0]);
	i = -1;
	while (map[0][++i] != '\0' )
	{
		if(map[0][i]!= '1'&& map[0][i]!= '\n' )
			return(-1);
	}
	i = -1;
	while (map[len-1][++i] != '\0')
	{
		if(map[0][i]!= '1'&& map[0][i]!= '\n')
			return(-1);
	}
	i = -1;
	while (map[++i] != NULL)
	{
		if(map[i][0] != '1')
			return(-1);
		if(map[i][size-2] != '1')
			return(-1);
	}
	return(0);
}

char **valid_maps_unes(char **map,int len)
{
	ft_printf("\no numero %d \n",valid_lines(map,len));
	return(map);
}


