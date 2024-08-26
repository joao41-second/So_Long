/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:58:03 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:57:50 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_imgs *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_retunr(t_imgs *data, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int *)(data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8)));
	return (color);
}

void	put_img(t_imgs img, t_imgs ret, int wx, int wy)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
		{
			pixel = my_mlx_pixel_retunr(&img, x, y);
			if (pixel != 0xff000000)
			{
				if (pixel != 0x000000)
				{
					if (pixel != 0xffffff)
						my_mlx_pixel_put(&ret, x + wx, y + wy, pixel);
				}
			}
		}
	}
}

t_imgs	if_p(t_vars vars, t_imgs ret, int x, int y)
{
	put_img(vars.imgs[1], ret, x, y);
	if (vars.player.set_palyer_anime == 0)
	{
		if (vars.frame < 7)
			put_img(vars.player.player[vars.frame], ret, x, y - 20);
		else
			put_img(vars.player.player[0], ret, x, y - 20);
	}
	else if (vars.player.set_palyer_anime == 1)
	{
		if (vars.frame < 7)
			put_img(vars.player.player_right[vars.frame], ret, x
				+ (vars.player.x * vars.frame), y + (vars.player.y
					* vars.frame) - 20);
		else
			put_img(vars.player.player[0], ret, x + (vars.player.x
					* vars.frame), y + (vars.player.y * vars.frame) - 20);
	}
	return (ret);
}
