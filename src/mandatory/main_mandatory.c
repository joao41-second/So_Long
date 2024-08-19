/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:13:47 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/19 10:59:50 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_ponter_len(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}

t_point	window_size(char **map)
{
	t_point	size;

	size.x = (ft_strlen(map[0]) - 1) * 16;
	size.y = ft_ponter_len(map) * 16;
	return (size);
}

void	window_start(char **map_copy)
{
	t_point	size;
	t_vars	vars;

	size = window_size(map_copy);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, size.x, size.y, "So_Long");
	mlx_hook(vars.win, DestroyNotify, 0l, &mlx_loop_end, vars.mlx);
	map_in_img(map_copy, &vars);
	mlx_loop(vars.mlx);
	img_free(vars, vars.imgs);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
