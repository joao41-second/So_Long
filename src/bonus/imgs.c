/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:59:16 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/16 16:16:05 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_imgs* img_set(t_vars vars,t_imgs* imgs)
{
	int		width;
	int		height;
	
	imgs[0].img = mlx_xpm_file_to_image(vars.mlx,"img/textures/blocks/ground.xpm",&width,&height);
	imgs[0].addr = mlx_get_data_addr(imgs[0].img, &imgs[0].bits_per_pixel,&imgs[0].line_length, &imgs[0].endian);
	imgs[0].width = width; 
	imgs[0].height = height;
	imgs[1].img = mlx_xpm_file_to_image(vars.mlx,"img/textures/blocks/wall.xpm",&width,&height);
	imgs[1].addr = mlx_get_data_addr(imgs[1].img, &imgs[1].bits_per_pixel,&imgs[1].line_length, &imgs[1].endian);
	imgs[1].width = width; 
	imgs[1].height = height;
	imgs[2].img = mlx_xpm_file_to_image(vars.mlx,"img/textures/player/player_j0.xpm",&width,&height);
	imgs[2].addr = mlx_get_data_addr(imgs[2].img, &imgs[2].bits_per_pixel,&imgs[2].line_length, &imgs[2].endian);
	imgs[2].width = width; 
	imgs[2].height = height;
	imgs[3].img = mlx_xpm_file_to_image(vars.mlx,"./img/mand/coin-_16_16.xpm",&width,&height);
	imgs[3].width = width; 
	imgs[3].height = height;
	imgs[4].img = mlx_xpm_file_to_image(vars.mlx,"./img/mand/bamboo_door_top.xpm",&width,&height);
	imgs[4].width = width; 
	imgs[4].height = height;
	
	return(imgs);
}

void img_free(t_vars vars,t_imgs *imgs)
{
	mlx_destroy_image(vars.mlx,imgs[0].img);
	mlx_destroy_image(vars.mlx,imgs[1].img);
	mlx_destroy_image(vars.mlx,imgs[2].img);
	mlx_destroy_image(vars.mlx,imgs[3].img);
	mlx_destroy_image(vars.mlx,imgs[4].img);
}





void	my_mlx_pixel_put(t_imgs *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
unsigned int	my_mlx_pixel_retunr(t_imgs *data, int x, int y)
{
	unsigned int color;

	color = *(unsigned int *)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
	return(color);
}
void put_img(t_imgs img,t_imgs ret ,int wx,int wy)
{
	int x ;
	int y ;
	unsigned int pixel;
	
	y = -1;
	while(++y < 64)
	{
		x = -1;
		while(++x < 64)
		{
			pixel = my_mlx_pixel_retunr(&img,x,y);
			
			if (pixel != 0xff000000){
			my_mlx_pixel_put(&ret,x+wx,y+wy,pixel);
			}
		}
	}
	
}




t_imgs creat_windo(t_imgs *img,t_vars vars,char ** map )
{
	
	t_imgs ret;
	int x;
	int y;
	int i;
	int e;
	e = vars.size.x ;
	vars.size.y = vars.size.x;
	vars.size.x = e;

	
	ret.img = mlx_new_image(vars.mlx,vars.size.y, vars.size.x);
	ret.addr = mlx_get_data_addr(ret.img,&ret.bits_per_pixel,&ret.line_length,&ret.endian);
	
	e = -1;
	
	x = vars.size.x /4  ;
	y = vars.size.y /40;
	
	
		
	while( map[++e] != NULL){
		i = -1;
		x =  (vars.size.x /4)+(-32 * e) ;
		y = (vars.size.y /40)	+ (16  * e);
		while( map[e] [++i] != '\0' )
		{
		y+=16;
		x+=32;
		if(map[e][i] == '0')
			put_img(img[1],ret,x,y);
		else if(map[e][i] == 'P')
			put_img(img[2],ret,x,y);
		else
			put_img(img[0],ret,x,y);
	
		}
		
		
		
		ft_printf("x =%d,y=%d o e = %d\n",x,y,e);
	}
	
	
	
	
	return(ret);
}


void render_imgs(t_vars vars, t_imgs *imgs,char **map)
{
	// t_point size;
	// int x;
	// int y;

	// size.x = 0;
	// size.y = 0;
	// y = -1;
	// if(map == NULL)
	// 	return;
	// while (map[++y] != NULL)
	// {
	// 	x = -1;
	// 	size.x = 0;
	// 	while (map[y][++x] != '\0')
	// 	{
	// 		if(map[y][x] == '0')
	// 			mlx_put_image_to_window(vars.mlx, vars.win, imgs[1].img, size.x,  size.y);
	// 		if(map[y][x] == '1')
	// 			mlx_put_image_to_window(vars.mlx, vars.win, imgs[0].img,  size.x,  size.y);
	// 		if(map[y][x] == 'C')
	// 			mlx_put_image_to_window(vars.mlx, vars.win, imgs[3].img,  size.x,  size.y);
	// 		if(map[y][x] == 'E')
	// 			mlx_put_image_to_window(vars.mlx, vars.win, imgs[4].img,  size.x,  size.y);
	// 		if(map[y][x] == 'P')
	// 			mlx_put_image_to_window(vars.mlx, vars.win, imgs[2].img,  size.x,  size.y);
	// 		size.x+=16;
	// 	}
	// 	size.y+=16;
	// }
	if(map){}
	if(imgs){}
	
	t_imgs test2;
	// int		width;
	// int		height;
	
	// test.img = mlx_xpm_file_to_image(vars.mlx,"img/textures/blocks/obs.xpm",&width,&height);
	// test.height = height;
	// test.width = width;

	

	test2 = creat_windo(imgs,vars,map);
	
	mlx_put_image_to_window(vars.mlx, vars.win, test2.img, 0,  0);

	// mlx_put_image_to_window(vars.mlx, vars.win, test.img, 0,  0);
	// 	mlx_put_image_to_window(vars.mlx, vars.win, test.img, 64-32,  64-47);

	//mlx_put_image_to_window(vars.mlx, vars.win, imgs[0].img, 64-32,  64-17);


}

void map_in_img(char **map,t_vars *vars)
{
	img_set(*vars,vars->imgs);
	vars->map = map;
	render_imgs(*vars,vars->imgs,map);
	t_point set_new_palyer;
	set_new_palyer = locat_player(vars->map);
	if(set_new_palyer.x == 0){}
	mlx_hook(vars->win, 2, 1L<<0, key, vars);

}