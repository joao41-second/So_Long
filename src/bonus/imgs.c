/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:59:16 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:35:06 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	anime_update(int frame, int max)
{
	if (frame > max)
	{
		frame = 0;
	}
	frame++;
	return (frame);
}

int	frams(t_vars *vars)
{
	static long long	now;
	long long			diff_mil;
	char				*muv;
	static int			frame = 0;

	if (now == 0)
		now = milltimestamp();
	diff_mil = milltimestamp() - now;
	if (diff_mil > 15)
	{
		if (frame > 30)
			frame = 0;
		if (vars->frame == 6)
			vars->player.set_palyer_anime = 0;
		vars->frame = frame;
		render_imgs(*vars, vars->imgs, vars->map);
		if (frame == 30)
			dell_boll(vars->map);
		usleep(10000);
		frame++;
		muv = ft_itoa(vars->muvs);
		mlx_string_put(vars->mlx, vars->win, 10, 10, 0xffff0000, muv);
		free(muv);
	}
	return (1);
}

void	set_vars(t_vars *vars)
{
	vars->player.x = 0;
	vars->player.y = 0;
	vars->muvs = 0;
}

void	map_in_img(char **map, t_vars *vars)
{
	t_imgs	player[8];
	t_imgs	slime[2];
	t_imgs	player_right[8];
	t_imgs	player_atak[10];

	set_vars(vars);
	vars->player.player = img_name(vars, "./img/textures/player/sandart/frame_",
			7, player);
	vars->slime = img_name(vars, "img/textures/slime/slime_", 1, slime);
	vars->player.player_right = img_name(vars,
			"./img/textures/player/dir_and/frame_", 7, player_right);
	vars->player.player_atak = img_name(vars,
			"./img/textures/fire_atack/frame_", 10, player_atak);
	vars->player.set_palyer_anime = 0;
	vars->frame = 3;
	img_set(*vars, vars->imgs);
	vars->map = ger_mob(map);
	render_imgs(*vars, vars->imgs, map);
	mlx_hook(vars->win, 2, 1L << 0, key, vars);
	mlx_loop_hook(vars->mlx, frams, vars);
	mlx_loop(vars->mlx);
	free_name(vars, 7, player_right);
	free_name(vars, 7, player);
	free_name(vars, 1, slime);
	free_name(vars, 10, player_atak);
}
