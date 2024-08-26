/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:59:16 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:41:00 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#include "../so_long.h"

t_imgs	*img_set(t_vars vars, t_imgs *imgs)
{
	int	width;
	int	height;

	imgs[0].img = mlx_xpm_file_to_image(vars.mlx,
			"./img/mand/bamboo_mosaic.xpm", &width, &height);
	imgs[0].width = width;
	imgs[0].height = height;
	imgs[1].img = mlx_xpm_file_to_image(vars.mlx, "./img/mand/bamboo_block.xpm",
			&width, &height);
	imgs[1].width = width;
	imgs[1].height = height;
	imgs[2].img = mlx_xpm_file_to_image(vars.mlx, "./img/mand/palyer-16_16.xpm",
			&width, &height);
	imgs[2].width = width;
	imgs[2].height = height;
	imgs[3].img = mlx_xpm_file_to_image(vars.mlx, "./img/mand/coin-_16_16.xpm",
			&width, &height);
	imgs[3].width = width;
	imgs[3].height = height;
	imgs[4].img = mlx_xpm_file_to_image(vars.mlx,
			"./img/mand/bamboo_door_top.xpm", &width, &height);
	imgs[4].width = width;
	imgs[4].height = height;
	return (imgs);
}

void	img_free(t_vars vars, t_imgs *imgs)
{
	mlx_destroy_image(vars.mlx, imgs[0].img);
	mlx_destroy_image(vars.mlx, imgs[1].img);
	mlx_destroy_image(vars.mlx, imgs[2].img);
	mlx_destroy_image(vars.mlx, imgs[3].img);
	mlx_destroy_image(vars.mlx, imgs[4].img);
}

static void	put_img_window(t_vars vars, t_imgs *imgs, char map, t_point size)
{
	if (map == '0')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs[1].img, size.x,
			size.y);
	if (map == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs[0].img, size.x,
			size.y);
	if (map == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs[3].img, size.x,
			size.y);
	if (map == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs[4].img, size.x,
			size.y);
	if (map == 'P')
		mlx_put_image_to_window(vars.mlx, vars.win, imgs[2].img, size.x,
			size.y);
}

void	render_imgs(t_vars vars, t_imgs *imgs, char **map)
{
	t_point	size;
	int		x;
	int		y;

	size.x = 0;
	size.y = 0;
	y = -1;
	if (map == NULL)
		return ;
	while (map[++y] != NULL)
	{
		x = -1;
		size.x = 0;
		while (map[y][++x] != '\0')
		{
			put_img_window(vars, imgs, map[y][x], size);
			size.x += 16;
		}
		size.y += 16;
	}
}

void	map_in_img(char **map, t_vars *vars)
{
	img_set(*vars, vars->imgs);
	vars->map = map;
	render_imgs(*vars, vars->imgs, map);
	mlx_hook(vars->win, 2, 1L << 0, key, vars);
}
