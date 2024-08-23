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
#include <sys/time.h>

t_imgs* img_set(t_vars vars,t_imgs* imgs)
{
	int		width;
	int		height;
	
	imgs[0].img = mlx_xpm_file_to_image(vars.mlx,"img/textures/special/10.xpm",&width,&height);
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
	imgs[3].img = mlx_xpm_file_to_image(vars.mlx,"img/textures/items/bonus.xpm",&width,&height);
	imgs[3].addr = mlx_get_data_addr(imgs[3].img, &imgs[3].bits_per_pixel,&imgs[3].line_length, &imgs[3].endian);
	imgs[3].width = width; 
	imgs[3].height = height;
	imgs[4].img = mlx_xpm_file_to_image(vars.mlx,"img/textures/special/16.xpm",&width,&height);
	imgs[4].addr = mlx_get_data_addr(imgs[4].img, &imgs[4].bits_per_pixel,&imgs[4].line_length, &imgs[3].endian);
	imgs[4].width = width; 
	imgs[4].height = height;
	
	return(imgs);
}


t_imgs *img_name(t_vars *vars,char *name,int len,t_imgs *imgs)
{
	int i;
	int		width;
	int		height;
	char *str;
	char *str2;
	char *n;
	i = -1;
	while(++i != len)
	{
		n = ft_itoa(i);
		str = ft_strjoin(name,n);
		str2 = ft_strjoin(str,".xpm");
		ft_printf(str2);
		width =0;
		height = 0;
		imgs[i].img = mlx_xpm_file_to_image(vars->mlx,str2,&width,&height);
		imgs[i].addr = mlx_get_data_addr(imgs[i].img, &imgs[i].bits_per_pixel,&imgs[i].line_length, &imgs[i].endian);
		imgs[i].width = width; 
		imgs[i].height = height;
		free(str2);
		free(str);
		free(n);
	}
	
	return(imgs);
}
t_imgs *free_name(t_vars *vars,int len,t_imgs *imgs)
{
	int i;
	i = -1;
	while(++i != len)
	{
		
		mlx_destroy_image(vars->mlx,imgs[i].img);

	}
	
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
			
			if (pixel != 0xff000000 ){
				if (pixel != 0x000000){
					if (pixel != 0xffffff)
						my_mlx_pixel_put(&ret,x+wx,y+wy,pixel);
					}
			}
		}
	}
	
}




t_imgs creat_windo(t_imgs *img,t_vars vars,char ** map )
{
	
	static t_imgs ret;
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
	
	int sav = 0;
		
	while( map[++e] != NULL ){
		 if(map[e+1] == NULL && sav == 0)
		 {
			sav++;
			e--;
		 } 
			// break;
		i = -1;
		x =  (vars.size.x /4)+(-32 * e) ;
		y = (vars.size.y /40)+ (16  * e);
		
		while( map[e] [++i] != '\0' )
		{
			if(map[e] [i+1] == '\0')
				break;
		y+=16;
		x+=32;
		
		 if(map[e][i] == 'P')
		{
			
			put_img(img[1],ret,x,y);
			if(vars.player.set_palyer_anime == 0)
			{
				if(vars.frame < 7)
					put_img(vars.player.player[vars.frame],ret,x,y-20);
				else 
					put_img(vars.player.player[0],ret,x,y-20);
			}
			else if (vars.player.set_palyer_anime == 1)
			{
				if(vars.frame < 7)
					put_img(vars.player.player_right[vars.frame],ret,x+(vars.player.x*vars.frame),y+(vars.player.y*vars.frame)-20);
				else 
					put_img(vars.player.player[0],ret,x+(vars.player.x*vars.frame),y+(vars.player.y*vars.frame)-20);

			}
		}
		else if(map[e][i] == 'M')
		{
			put_img(img[1],ret,x,y);
			put_img(vars.slime[0],ret,x,y);
		}
		else if(map[e][i] == 'B')
		{
			put_img(img[1],ret,x,y);
			put_img(img[2],ret,x,y);
		}
		else if(map[e][i] == 'C')
		{

			put_img(img[1],ret,x,y);
			put_img(img[3],ret,x,y-10);
		}
		else if(map[e][i] == 'E')
			put_img(img[4],ret,x,y+16);
		else if(map[e][i] == '0')
			put_img(img[1],ret,x,y);
		else 
			put_img(img[0],ret,x,y);
		}
		//ft_printf("x =%d,y=%d o e = %d\n",x,y,e);
	}
	return(ret);
}


void render_imgs(t_vars vars, t_imgs *imgs,char **map)
{

	
	if(map){}
	if(imgs){}
	t_imgs test2;
	test2 = creat_windo(imgs,vars,map);
	mlx_put_image_to_window(vars.mlx, vars.win, test2.img, 0,  0);
	mlx_destroy_image(vars.mlx,test2.img);

}

int milltimestamp()
{
	 struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 ;
	return(ms);
}

int frams(t_vars *vars)
{
	static long long  now;
	long long diff_mil;

	if(now == 0)
		now = milltimestamp();
	diff_mil =  milltimestamp() - now;
	//ft_printf("frames %d\n",diff_mil);
	if(diff_mil > 15){
	static int frame = 0;
	if(frame == 7)
		frame = 0;
	if(vars->win){}
	//ft_printf("oi");
	if(vars->frame == 6)
		vars->player.set_palyer_anime = 0;
	vars->frame = frame;
	usleep(90000);
	render_imgs(*vars,vars->imgs,vars->map);
	if(frame == 0)
		dell_boll(vars->map);
	
	
	frame++;
	//now = milltimestamp();
	}
	
	return(1);
}

void map_in_img(char **map,t_vars *vars)
{
	t_imgs player[8];
	t_imgs slime[2];
	t_imgs player_right[8];
	vars->player.x = 0;
	vars->player.y = 0;

	vars->player.player = img_name(vars,"./img/textures/player/sandart/frame_",7,player);
	vars->slime = img_name(vars,"img/textures/slime/slime_",1,slime);
	vars->player.player_right =  img_name(vars,"./img/textures/player/dir_and/frame_",7,player_right);
	vars->player.set_palyer_anime = 0;
	vars->frame = 3;
	img_set(*vars,vars->imgs);
	vars->map =   ger_mob(map);
	render_imgs(*vars,vars->imgs,map);
	
	mlx_hook(vars->win, 2, 1L<<0, key, vars);

	mlx_loop_hook(vars->mlx,frams,vars);
	mlx_loop(vars->mlx);
	free_name(vars,7,player_right);
	free_name(vars,7,player);
	free_name(vars,1,slime);
	
	
}