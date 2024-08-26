/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_componets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:00:58 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:43:04 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	chek_chars_invalid(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (verfic_char_list("10CEP\n", map[y][x]) == 0)
				return (-1);
		}
	}
	return (0);
}

t_point	set_cord(int x, int y, t_point cord)
{
	cord.x += x;
	cord.y += y;
	return (cord);
}

void	flood_fill(char **tab, t_point size, t_point begin, char *list)
{
	tab[begin.y][begin.x] = 'o';
	if (begin.y > 0 && verfic_char_list(list, tab[begin.y - 1][begin.x]) == 1)
	{
		flood_fill(tab, size, set_cord(0, -1, begin), list);
	}
	if (begin.x > 0 && verfic_char_list(list, tab[begin.y][begin.x - 1]) == 1)
	{
		flood_fill(tab, size, set_cord(-1, 0, begin), list);
	}
	if (begin.y < size.y - 1 && verfic_char_list(list, tab[begin.y
				+ 1][begin.x]) == 1)
	{
		flood_fill(tab, size, set_cord(0, +1, begin), list);
	}
	if (begin.x < size.x - 1 && verfic_char_list(list, tab[begin.y][begin.x
			+ 1]) == 1)
	{
		flood_fill(tab, size, set_cord(+1, 0, begin), list);
	}
}

int	locat_colt(char **map, int i)
{
	int	x;
	int	y;
	int	c[3];

	c[0] = i;
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
	if (c[2] != 0 || c[1] != 0 || c[0] != i)
		return (c[0]);
	return (0);
}

char	**map_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
	{
		free(map[i]);
	}
	free(map);
	return (NULL);
}
