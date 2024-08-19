/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaid_unes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:47:41 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/19 12:23:09 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	valid_lines(char **map, int len)
{
	int	i;
	int	size;

	size = ft_strlen(map[0]);
	i = -1;
	while (map[0][++i] != '\0')
	{
		if (map[0][i] != '1' && map[0][i] != '\n')
			return (-1);
	}
	i = -1;
	while (map[len - 1][++i] != '\0')
	{
		if (map[0][i] != '1' && map[0][i] != '\n')
			return (-1);
	}
	i = -1;
	while (map[++i] != NULL)
	{
		if (map[i][0] != '1')
			return (-1);
		if (map[i][size - 2] != '1')
			return (-1);
	}
	return (0);
}

static	int	valid_size(char **map)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(map[0]);
	while (map[++i] != NULL)
	{
		if (map[i + 1] == NULL)
			size--;
		if ((int)ft_strlen(map[i]) != size)
			return (-1);
	}
	return (0);
}

static int	char_cunt(char **map)
{
	int	x;
	int	y;
	int	c[3];

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'C')
				c[0]++;
			if (map[y][x] == 'E')
				c[1]++;
			if (map[y][x] == 'P')
				c[2]++;
		}
	}
	if (c[2] == 1 && c[1] == 1)
		return (c[0]);
	return (0);
}

t_point	locat_player(char **map)
{
	int		x;
	int		y;
	t_point	player;

	y = -1;
	player.x = 0;
	player.y = 0;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				player.x = x;
				player.y = y;
				return (player);
			}
		}
	}
	return (player);
}

char	**valid_maps_unes(char **map, int len)
{
	t_point	start;
	t_point	size;

	if (valid_lines(map, len) == -1 || valid_size(map) == -1
		|| char_cunt(map) == 0 || chek_chars_invalid(map) == -1)
	{
		ft_printf("error\n-invalid_characters");
		return (NULL);
	}
	start = locat_player(map);
	if (start.x == 0 && start.y == 0)
		return (NULL);
	size.y = len - 1;
	size.x = ft_strlen(map[0]) - 1;
	flood_fill(map, size, start, "C0EP");
	if (locat_colt(map, 0) != 0)
	{
		ft_printf("error\n-not possibe end game");
		return (NULL);
	}
	return (map);
}
