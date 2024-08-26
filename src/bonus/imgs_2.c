/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:50:11 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:57:15 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	compact(t_imgs imgs, int a, int b);
t_imgs	*img_set(t_vars vars, t_imgs *imgs);
t_imgs	*img_name(t_vars *vars, char *name, int len, t_imgs *imgs);
t_imgs	*free_name(t_vars *vars, int len, t_imgs *imgs);
void	img_free(t_vars vars, t_imgs *imgs);

void	compact(t_imgs imgs, int a, int b)
{
	imgs.width = a;
	imgs.height = b;
}

t_imgs	*img_set(t_vars vars, t_imgs *imgs)
{
	int	width;
	int	height;

	imgs[0].img = mlx_xpm_file_to_image(vars.mlx, "img/textures/special/10.xpm",
			&width, &height);
	imgs[0].addr = mlx_get_data_addr(imgs[0].img, &imgs[0].bits_per_pixel,
			&imgs[0].line_length, &imgs[0].endian);
	compact(imgs[0], width, height);
	imgs[1].img = mlx_xpm_file_to_image(vars.mlx,
			"img/textures/blocks/wall.xpm", &width, &height);
	imgs[1].addr = mlx_get_data_addr(imgs[1].img, &imgs[1].bits_per_pixel,
			&imgs[1].line_length, &imgs[1].endian);
	compact(imgs[1], width, height);
	imgs[3].img = mlx_xpm_file_to_image(vars.mlx,
			"img/textures/items/bonus.xpm", &width, &height);
	imgs[3].addr = mlx_get_data_addr(imgs[3].img, &imgs[3].bits_per_pixel,
			&imgs[3].line_length, &imgs[3].endian);
	compact(imgs[3], width, height);
	imgs[4].img = mlx_xpm_file_to_image(vars.mlx, "img/textures/special/16.xpm",
			&width, &height);
	imgs[4].addr = mlx_get_data_addr(imgs[4].img, &imgs[4].bits_per_pixel,
			&imgs[4].line_length, &imgs[3].endian);
	compact(imgs[4], width, height);
	return (imgs);
}

t_imgs	*img_name(t_vars *vars, char *name, int len, t_imgs *imgs)
{
	int		i;
	int		width;
	char	*str;
	char	*str2;
	char	*n;

	i = -1;
	while (++i != len)
	{
		n = ft_itoa(i);
		str = ft_strjoin(name, n);
		str2 = ft_strjoin(str, ".xpm");
		width = 0;
		imgs[i].img = mlx_xpm_file_to_image(vars->mlx, str2, &width, &width);
		imgs[i].addr = mlx_get_data_addr(imgs[i].img, &imgs[i].bits_per_pixel,
				&imgs[i].line_length, &imgs[i].endian);
		imgs[i].width = width;
		free(str2);
		free(str);
		free(n);
	}
	return (imgs);
}

t_imgs	*free_name(t_vars *vars, int len, t_imgs *imgs)
{
	int	i;

	i = -1;
	while (++i != len)
	{
		mlx_destroy_image(vars->mlx, imgs[i].img);
	}
	return (imgs);
}

void	img_free(t_vars vars, t_imgs *imgs)
{
	mlx_destroy_image(vars.mlx, imgs[0].img);
	mlx_destroy_image(vars.mlx, imgs[1].img);
	mlx_destroy_image(vars.mlx, imgs[3].img);
	mlx_destroy_image(vars.mlx, imgs[4].img);
}
