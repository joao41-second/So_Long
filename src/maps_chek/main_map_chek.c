#include "../so_long.h"


void map_print(char **map)
{
	int i;

	i = -1;

	while (map[++i] != NULL)
	{
		ft_printf("%s",map[i]);
	}
}

void map_free(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL)
	{
		free(map[i]);
	}
	free(map);
}

char **aloc_map(int len , char *url)
{
	int fd;
	char **map;
	
	int i;

	i = -1;
	fd = open(url,O_RDONLY );
	map = (char**)malloc((len+1) * sizeof(char *));
	if(map == NULL)
		return(NULL);
	while (++i <= len )
	{
		map[i] = get_next_line(fd);
		if(map[i] == NULL)
			break;
	}
	map[len] = NULL;
	close(fd);
	return(map);
}




char **valid_map_main(char *url)
{
	int fd;
	char *line;
	int len;
	char **map;

	len = 0;
	fd = open(url,O_RDONLY );
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while(line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	
	map = aloc_map(len,url);
	if(map == NULL)
		return(NULL);
	map_print(map);
	valid_maps_unes(map,len);
	
	map_free(map);
	close(fd);
	return(NULL);	
}


