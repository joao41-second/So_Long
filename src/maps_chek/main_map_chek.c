/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map_chek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:47:27 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/19 12:07:46 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_print(char **map)
{
	int	i;

	i = -1;
	ft_printf("\n");
	while (map[++i] != NULL)
	{
		ft_printf("%s", map[i]);
	}
	ft_printf("%s", map[i]);
}

char	**aloc_map(int len, char *url)
{
	int		fd;
	char	**map;
	int		i;

	i = -1;
	fd = open(url, O_RDONLY);
	map = (char **)malloc((len + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	while (++i < len)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
	}
	map[len] = NULL;
	close(fd);
	return (map);
}

static int	ft_len_file(char *url)
{
	int		len;
	char	*line;
	int		fd;

	len = 0;
	fd = open(url, O_RDONLY);
	if (fd == -1)
	{
		return (0);
		close(fd);
	}
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

char	**valid_map_main(char *url)
{
	int		fd;
	int		len;
	char	**map;
	char	**copy;

	map = NULL;
	len = ft_len_file(url);
	if (len == 0)
	{
		ft_printf("error\n-map not exits");
		return (NULL);
	}
	map = aloc_map(len, url);
	if (map == NULL)
	{
		return (NULL);
		close(fd);
	}
	copy = valid_maps_unes(map, len);
	if (copy == NULL)
		map_free(map);
	return (copy);
}
