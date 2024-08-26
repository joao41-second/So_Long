/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_if.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:29:37 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:58:46 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_imgs	if_c(t_vars vars, t_imgs ret, int x, int y)
{
	put_img(vars.imgs[1], ret, x, y);
	put_img(vars.imgs[3], ret, x, y - 10);
	return (ret);
}

t_imgs	if_b(t_vars vars, t_imgs ret, int x, int y)
{
	put_img(vars.imgs[1], ret, x, y);
	if (vars.frame < 9)
		put_img(vars.player.player_atak[vars.frame], ret, x, y);
	else
		put_img(vars.player.player_atak[vars.frame / 4], ret, x, y);
	return (ret);
}

t_imgs	if_m(t_vars vars, t_imgs ret, int x, int y)
{
	put_img(vars.imgs[1], ret, x, y);
	put_img(vars.slime[0], ret, x, y);
	return (ret);
}

t_imgs	set_frame(t_vars vars, t_imgs ret, t_point e_i, t_point y_x)
{
	int	e;
	int	i;
	int	x;
	int	y;

	e = e_i.x;
	i = e_i.y;
	x = y_x.x;
	y = y_x.y;
	if (vars.map[e][i] == 'P')
		ret = if_p(vars, ret, x, y);
	else if (vars.map[e][i] == 'M')
		ret = if_m(vars, ret, x, y);
	else if (vars.map[e][i] == 'B')
		ret = if_b(vars, ret, x, y);
	else if (vars.map[e][i] == 'C')
		ret = if_c(vars, ret, x, y);
	else if (vars.map[e][i] == 'E')
		put_img(vars.imgs[4], ret, x, y + 16);
	else if (vars.map[e][i] == '0')
		put_img(vars.imgs[1], ret, x, y);
	else
		put_img(vars.imgs[0], ret, x, y);
	return (ret);
}
