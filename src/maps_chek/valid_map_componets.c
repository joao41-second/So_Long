/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_componets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:00:58 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/16 17:34:32 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int chek_chars_invalid(char **map)
{
	int x;
	int y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
		  if(verfic_char_list("10CEP\n",map[y][x]) == 0)
		  	return(-1);
		}
	}
	return(0);
}

void  flood_fill(char **tab, t_point size, t_point begin,char *list)
{
   
    t_point novas_codenadas;
     tab[begin.y][begin.x] = 'o';
    
    if(begin.y > 0 && verfic_char_list(list, tab[begin.y - 1][begin.x] )== 1 )
    {
        novas_codenadas.x = begin.x;
        novas_codenadas.y = begin.y-1;
        flood_fill(tab,size,novas_codenadas,list);
    }
    if(begin.x > 0 && verfic_char_list(list, tab[begin.y][begin.x -1]) == 1)
    {
        novas_codenadas.x = begin.x-1;
        novas_codenadas.y = begin.y;
        flood_fill(tab,size,novas_codenadas,list);
    }
    if(begin.y < size.y-1 && verfic_char_list(list, tab[begin.y+1][begin.x]) == 1)
    {
        novas_codenadas.x = begin.x;
        novas_codenadas.y = begin.y +1;
        flood_fill(tab,size,novas_codenadas,list);
    }
    if (begin.x < size.x-1 && verfic_char_list(list, tab[begin.y][begin.x+1]) == 1)
    {
        novas_codenadas.x = begin.x + 1;
        novas_codenadas.y = begin.y;
        flood_fill(tab,size,novas_codenadas,list);
    }
}

int locat_colt(char **map)
{
	int x;
	int y;
	int c[3];

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if(map[y][x] == 'C')
				c[0]++;
			if(map[y][x] == 'E')
				c[1]++;
			if(map[y][x] == 'P')
				c[2]++;
		}
	}
	if(c[2] != 0 || c[1] != 0 ||  c[0] != 0 )
		return(c[0]);
	return(0);
}

