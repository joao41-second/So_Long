

#include "./src/so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_imgs {
	int		width;
	int		height;
	void*	img;
}				 t_imgs;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char 	**map;
	t_imgs 	imgs[6];
}				t_vars;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


// int	main(void)
// {
	
// 	void *img;
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");

// 	int		img_width;
// 	int		img_height;
	


// 	img = mlx_xpm_file_to_image(vars.mlx,"./img/Untitled.xpm",&img_width,&img_height);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
// 	//sleep(2);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img, 250, 0);

	

// 	mlx_destroy_image(vars.mlx,img);

// 	//mlx_hook(vars.win, 2, 1L<<0, sclose, &vars);

// 	mlx_mouse_hook(vars.win,sclose, &vars);

	
// 	mlx_loop(vars.mlx);

// 	sleep(5);
// 	///mlx_destroy_window(vars.mlx,vars.win);
// 	mlx_destroy_display(vars.mlx);
// 	free(vars.mlx);
// }
int ft_ponter_len(char **map)
{
	int i;
	i = 0;
	while(map[i] != NULL)
	{
		i++;
	}
	return(i);
}

t_point window_size(char** map) 
{
	t_point size;
	

	size.x = ft_strlen(map[0]) * 16;
	size.y = ft_ponter_len(map) * 16;
	return(size);
}

char** new_locat_play(char **map,t_point new_tp)
{
	t_point tp;

	tp = locat_player(map);
	if(map[new_tp.y][new_tp.x] != '1')
	{
		if(map[new_tp.y][new_tp.x] == 'E' && locat_colt(map) == 0){
				
			map[new_tp.y][new_tp.x] = 'P';
			map[tp.y][tp.x] = '0';
		}
		else if (map[new_tp.y][new_tp.x] != 'E'){
			map[new_tp.y][new_tp.x] = 'P';
			map[tp.y][tp.x] = '0';
		}
	}
	return(map);
}


t_imgs* img_set(t_vars vars,t_imgs* imgs)
{
	int		width;
	int		height;
	
	imgs[0].img = mlx_xpm_file_to_image(vars.mlx,"./img/mand/bamboo_mosaic.xpm",&width,&height);
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

void render_imgs(t_vars vars, t_imgs *imgs,char **map)
{
	t_point size;
	int x;
	int y;

	size.x = 0;
	size.y = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		size.x = 0;
		while (map[y][++x] != '\0')
		{
			if(map[y][x] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, imgs[1].img, size.x,  size.y);
			if(map[y][x] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, imgs[0].img,  size.x,  size.y);
			if(map[y][x] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, imgs[3].img,  size.x,  size.y);
			if(map[y][x] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, imgs[4].img,  size.x,  size.y);
			if(map[y][x] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, imgs[2].img,  size.x,  size.y);
			size.x+=16;
		}
		size.y+=16;
	}

}

int	sclose(int keycode, t_vars *vars )
{
	t_point set_new_palyer;
	if(keycode ){}
	if(vars){}
	set_new_palyer = locat_player(vars->map);
	if(set_new_palyer.x ){}

	if(keycode == 'w')
		set_new_palyer.y--;
	
	if(keycode == 's')
		set_new_palyer.y++;
	if(keycode == 'a')
		set_new_palyer.x--;
	if(keycode == 'd')
		set_new_palyer.x++;
	if(verfic_char_list("wasd",keycode)== 1)
	{
	vars->map = new_locat_play(vars->map,set_new_palyer);
	render_imgs(*vars,vars->imgs,vars->map);
	}
	return (0);
}
void map_in_img(char **map,t_vars vars)
{
	
	

	img_set(vars,vars.imgs);
	vars.map = map;
	render_imgs(vars,vars.imgs,map);
	t_point set_new_palyer;
	set_new_palyer = locat_player(vars.map);
	if(set_new_palyer.x == 0){}
	mlx_hook(vars.win, 2, 1L<<0, sclose, &vars);

	//sleep(15);
	//mlx_destroy_image(vars.mlx,vars.imgs[0].img);

}
void window_start(char **map,char **map_copy)
{
	t_point size;
	t_vars	vars;
	if(map == map_copy){}
	size = window_size(map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, size.x, size.y, "Hello world!");

	map_in_img(map_copy,vars);
	
	mlx_loop(vars.mlx);
	

	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free(vars.win);
}

int main(int ac,char **av)
{
	if(ac == 2)
	{
		char **map;
		char **map_copy;
		map = valid_map_main(av[1]);
		if(map == NULL)
		{
			ft_printf("error");
		}
		ft_printf("test %d",ft_ponter_len(map));
		map_copy = aloc_map(ft_ponter_len(map),av[1]);
		if(map_copy == NULL)
			return(0);
		window_start(map,map_copy);
		map_free(map);
		map_free(map_copy);
	
		

	}
	else
		ft_printf("nao tem map");

	if(av){}
}


