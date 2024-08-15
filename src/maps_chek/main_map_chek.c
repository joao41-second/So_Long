#include "../so_long.h"

void map_print(char **map)
{
	int i;
	i = -1;
	ft_printf("\n");
	while (map[++i] != NULL)
	{
		ft_printf("%s",map[i]);
	}
}

char** map_free(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL)
	{
		free(map[i]);
	}
	free(map);
	return (NULL);
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
		//ft_printf(map[i]);
		if(map[i] == NULL)
			break;
	}
	map[len] = NULL;
	close(fd);
	return(map);
}

// static char **free_null(char **map)
// {
// 	map_free(map);
// 	return(NULL);
// }

char **valid_map_main(char *url)
{
	int fd;
	char *line;
	int len;
	char **map;
	char **copy;
	

	map = NULL;
	len = 0;
	fd = open(url,O_RDONLY );
	if (fd == -1){
		return(NULL);
		close(fd);
	}
	line = get_next_line(fd);
	if(line == NULL)
	{
		free(line);
		return(NULL);
	}
	while(line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	map = aloc_map(len,url);

	if(map == NULL){
		return(NULL);
		close(fd);
	}
	map_print(map);
	copy = valid_maps_unes(map,len);
	
	if(copy == NULL)
		map_free(map);
	close(fd);
	return(copy);	
}


