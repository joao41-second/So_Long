/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:33:02 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 02:04:08 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point	ret_x_y(int x, int y)
{
	t_point	set;

	set.x = x;
	set.y = y;
	return (set);
}

t_imgs	while_y(t_imgs ret, t_vars vars, t_point e_i, t_point y_x)
{
	while (vars.map[e_i.x][++e_i.y] != '\0')
	{
		if (vars.map[e_i.x][e_i.y + 1] == '\0')
			break ;
		y_x = ret_x_y(y_x.x + 32, y_x.y + 16);
		ret = set_frame(vars, ret, e_i, y_x);
	}
	return (ret);
}

t_imgs	creat_windo( t_vars vars, char **map)
{
	static t_imgs	ret;
	int				sav;
	t_point			e_i;
	t_point			y_x;

	e_i.x = vars.size.x;
	vars.size.y = vars.size.x;
	vars.size.x = e_i.x;
	ret.img = mlx_new_image(vars.mlx, vars.size.y, vars.size.x);
	ret.addr = mlx_get_data_addr(ret.img, &ret.bits_per_pixel, &ret.line_length,
			&ret.endian);
	e_i.x = -1;
	y_x = ret_x_y(vars.size.x / 4, vars.size.y / 40);
	sav = 0;
	while (map[++e_i.x] != NULL)
	{
		if (map[e_i.x + 1] == NULL && sav++ == 0)
			e_i.x--;
		e_i.y = -1;
		y_x = ret_x_y((vars.size.x / 4) + (-32 * e_i.x), (vars.size.y / 40)
				+ (16 * e_i.x));
		ret = while_y(ret, vars, e_i, y_x);
	}
	return (ret);
}

void	render_imgs(t_vars vars, t_imgs *imgs, char **map)
{
	t_imgs	test2;

	if (map)
	{
	}
	if (imgs)
	{
	}
	test2 = creat_windo(vars, map);
	mlx_put_image_to_window(vars.mlx, vars.win, test2.img, 0, 0);
	mlx_destroy_image(vars.mlx, test2.img);
}

int	milltimestamp(void)
{
	struct timeval	tp;
	long int		ms;

	gettimeofday(&tp, NULL);
	ms = tp.tv_sec * 1000;
	return (ms);
}
