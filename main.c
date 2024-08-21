/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:09:50 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/19 12:23:45 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

char	**new_locat_play(char **map, t_point new_tp)
{
	t_point		tp;
	static int	muvs = 0;

	tp = locat_player(map);
	if (map[new_tp.y][new_tp.x] != '1')
	{
		if (map[new_tp.y][new_tp.x] == 'E' && locat_colt(map, 0) == 0)
			return (NULL);
		else if (map[new_tp.y][new_tp.x] != 'E' && map[new_tp.y][new_tp.x] != 'M'   )
		{
			muvs++;
			ft_printf("muvs = %d\n", muvs);
			map[new_tp.y][new_tp.x] = 'P';
			map[tp.y][tp.x] = '0';
		}
	}
	return (map);
}

static t_point	tp(int keycode, t_point set_new_palyer)
{
	if (keycode == 'w')
		set_new_palyer.y--;
	if (keycode == 's')
		set_new_palyer.y++;
	if (keycode == 'a')
		set_new_palyer.x--;
	if (keycode == 'd')
		set_new_palyer.x++;
	return (set_new_palyer);
}

static int	convert(int keycode)
{
	if (keycode == 65362)
		keycode = 'w';
	if (keycode == 65364)
		keycode = 's';
	if (keycode == 65363)
		keycode = 'd';
	if (keycode == 65361)
		keycode = 'a';
	return (keycode);
}

void flood(t_point size,char cord,char sin,char **map)
{
	int soma;
	if(sin == '+')
		soma = 1;
	else 
		soma = -1;
	if(cord == 'y')
	{
		if(map[size.y+soma][size.x] == '0' ||map[size.y+soma][size.x] == 'M')
		{
			map[size.y+soma][size.x] = 'B';
			size.y +=soma;
			
			flood(size,cord,sin,map);
			usleep(50000);
			
		}
		
	}
	else{
	if(map[size.y][size.x+soma] == '0' ||map[size.y][size.x+soma] == 'M')
		{
			map[size.y][size.x+soma] = 'B';
			size.x +=soma;
			
			flood(size,cord,sin,map);
			usleep(50000);
		}
	}

}

char **boll_anime(char **map,int dir)
{
	
	int b;
	b = 0;
	t_point size;
	//y = -1;
	 size = locat_player(map);

		if( dir == 'w'   )
		{
			flood(size,'y','-',map);
			b++;
		}
		else if( dir == 's' ){
			flood(size,'y','+',map);
			b++;
		}
		else if( dir == 'd'   )
		{
			flood(size,'x','+',map);
			b++;
		}
		else if( dir == 'a' ){
			flood(size,'x','-',map);
			b++;
		}

	return(map);
}

char **boll(char **map,int key)
{
	static int ultm;
	static int charg = 0;
	if(verfic_char_list("wasd", key) == 1)
		ultm = key;
	if(key == 32)
		charg++;
	if(charg > 15 && ultm != 0)
	{
	 map =boll_anime(map,ultm);
		charg = 0;
	}

	return (map);

}


void dell_boll(char**map)
{
	int		x;
	int		y;

	y = -1;
	if (map == NULL)
		return ;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if(map[y][x] == 'B')
				map[y][x]='0';
		}
	}
}



int	key(int keycode, t_vars *vars)
{
	t_point	set_new_palyer;
	void	*ok;

	set_new_palyer = locat_player(vars->map);
	ok = vars->mlx;
	boll(vars->map,keycode);
	if (keycode == 65307)
		mlx_loop_end(ok);
	keycode = convert(keycode);
	set_new_palyer = tp(keycode, set_new_palyer);
	if (verfic_char_list("wasd", keycode) == 1)
	{
		if (vars->map[set_new_palyer.y][set_new_palyer.x] == 'E'
			&& locat_colt(vars->map, 0) != 0)
		{
			set_new_palyer = tp(keycode, set_new_palyer);
		}
		vars->map = new_locat_play(vars->map, set_new_palyer);
		//render_imgs(*vars, vars->imgs, vars->map);
		if (vars->map == NULL)
			mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**map;
	char	**map_copy;

	if (ac == 2)
	{
		map = valid_map_main(av[1]);
		if (map == NULL)
		{
			return (0);
		}
		map_copy = aloc_map(ft_ponter_len(map), av[1]);
		if (map_copy == NULL)
			return (0);
		window_start(map_copy);
		map_free(map);
		map_free(map_copy);
	}
	else
		ft_printf("nao tem map");
}
