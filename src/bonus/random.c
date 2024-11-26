/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:54:11 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:57:06 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**boll_anime(char **map, int dir, t_point size)
{
	int	b;

	b = 0;
	if (dir == 'w')
	{
		flood(size, 'y', -1, map);
		b++;
	}
	else if (dir == 's')
	{
		flood(size, 'y', 1, map);
		b++;
	}
	else if (dir == 'd')
	{
		flood(size, 'x', 1, map);
		b++;
	}
	else if (dir == 'a')
	{
		flood(size, 'x', -1, map);
		b++;
	}
	return (map);
}

char	**boll(char **map, int key)
{
	static int	ultm;
	static int	charg = 0;

	if (verfic_char_list("wasd", key) == 1)
		ultm = key;
	if (key == 32)
		charg++;
	if (charg > 15 && ultm != 0)
	{
		map = boll_anime(map, ultm, locat_player(map));
		charg = 0;
	}
	return (map);
}

void	dell_boll(char **map)
{
	int	x;
	int	y;

	y = -1;
	if (map == NULL)
		return ;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'B')
				map[y][x] = '0';
		}
	}
}

void	flood(t_point size, char cord, int soma, char **map)
{
	if (cord == 'y')
	{
		if (map[size.y + soma][size.x] == '0' || map[size.y
			+ soma][size.x] == 'M')
		{
			map[size.y + soma][size.x] = 'B';
			size.y += soma;
			flood(size, cord, soma, map);
		}
	}
	else
	{
		if (map[size.y][size.x + soma] == '0' || map[size.y][size.x
			+ soma] == 'M')
		{
			map[size.y][size.x + soma] = 'B';
			size.x += soma;
			flood(size, cord, soma, map);
		}
	}
}
