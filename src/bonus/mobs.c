/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:55:50 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:56:39 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	ft_random(int min, int max)
{
	int	nubmer;

	nubmer = (rand() % (max - min + 1)) + min;
	if (nubmer >= 50)
	{
		return ('0');
	}
	return ('M');
}

char	**ger_mob(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == '0')
			{
				map[y][x] = ft_random(45, 100);
			}
		}
	}
	return (map);
}
