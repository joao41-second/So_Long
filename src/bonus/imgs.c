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
	
	imgs[0].img = mlx_xpm_file_to_image(vars.mlx,"img/textures/blocks/endlock.xpm",&width,&height);
	imgs[0].width = width; 
	imgs[0].height = height;
	imgs[1].img = mlx_xpm_file_to_image(vars.mlx,"./img/mand/bamboo_block.xpm",&width,&height);
	imgs[1].width = width; 
	imgs[1].height = height;
	imgs[2].img = mlx_xpm_file_to_image(vars.mlx,"./img/mand/palyer-16_16.xpm",&width,&height);
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


typedef struct	s_img_full {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img_full;


void	my_mlx_pixel_put(t_img_full *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
unsigned int	my_mlx_pixel_retunr(t_img_full *data, int x, int y)
{
	unsigned int color;

	color = *(unsigned int *)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
	return(color);
}

n_status *clore_set(char **img_fele,int i)
{
	n_status *colors;
	n_status *nod;
		++i;
	colors = ft_node_new(img_fele[i][1],0x00FF0000);

	while(ft_strncmp(img_fele[++i],"/* pixels */\n",5) != 0)
	{
		
		nod = ft_node_new(img_fele[i][1],(int)img_fele[i][5]);
		ft_node_add_front(&colors,nod);
		ft_printf("%c, convert\n,%s",img_fele[i][1],&img_fele[i][5]);
	}
	ft_print_list(colors,NULL);

	return(colors);
}



t_img_full comput_img(int i,char **file,n_status *list,t_vars vars)
{
	t_point size;
	t_img_full img;
	int x;
	int y;
	img.img = mlx_new_image(vars.mlx, 64, 64);
	img.addr = mlx_get_data_addr(img.img,&img.bits_per_pixel,&img.line_length,&img.endian);
	size.x = 0;
	size.y = i;
	y = i;
	while (file[++y] != NULL)
	{
	
		x = -1;
		size.x = 0;
		while (file[y][++x] != '\0')
		{
			
			if(file[y][x] != '"' ||file[y][x] != ',')
			{
				
				list = ft_node_start(list);
				while(list->next != NULL)
				{
					if(list->number == file[y][x])
					{
						if(list->number != 32)
							my_mlx_pixel_put(&img,x,y,list->index);
						if(list->number == 32)
							my_mlx_pixel_put(&img,x,y,0x00000000);
					}
					
					list = list->next;
				}
				size.x+=1;
			}
		}
		size.y+=1;
	 }
	 if(list){}
	 return(img);
}

t_img_full img_creat(char* url,t_vars vars)
{
	int i;
	t_img_full nada;
	char **img_fele;
	n_status *colors;
	i=-1;
	img_fele = aloc_map(ft_len_file(url),url);
	//map_print(img_fele);
	while(img_fele[++i] != NULL)
	{
		//ft_printf(img_fele[i]);
		if (ft_strncmp(img_fele[i], "/* columns rows colors chars-per-pixel */\n", 41) == 0)
		{
			ft_printf("ok");
			colors = clore_set(img_fele,i);
		}
		ft_printf(img_fele[i]);
		if(ft_strncmp(img_fele[i],"/* pixels */\n",5)==0)
			break;
	}
	colors = ft_node_start(colors);
	nada = comput_img(i,img_fele,colors,vars);
	return(nada);


}
t_img_full creat_windo(t_img_full img,t_point whindow,t_vars vars)
{
	// char *imgs;
	t_img_full ret;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,&img.line_length, &img.endian);
	ret.img = mlx_new_image(vars.mlx, whindow.y, whindow.x);
	ret.addr = mlx_get_data_addr(ret.img,&ret.bits_per_pixel,&ret.line_length,&ret.endian);
	
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
			if (pixel != 0x00000000){
			my_mlx_pixel_put(&ret,x+30,y+30,pixel);
			}
		}
	}
	y = -1;
	while(++y < 64)
	{
		x = -1;
		while(++x < 64)
		{	
			pixel = my_mlx_pixel_retunr(&img,x,y);
				if (pixel != 0x00000000){
			my_mlx_pixel_put(&ret,x+50,y+50,pixel);
			}
		}
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
	t_img_full test;
	t_img_full test2;
	int		width;
	int		height;
	
	test.img = mlx_xpm_file_to_image(vars.mlx,"img/textures/blocks/endlock.xpm",&width,&height);
	test.height = height;
	test.width = width;
	t_point wind;
	wind.x = 200;
	wind.y = 200;
	test2 = creat_windo(test,wind,vars);
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