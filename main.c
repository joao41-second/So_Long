

#include "./src/so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	sclose(int keycode,int x,int y, t_vars *vars)
{

	if(keycode ){}
	if(vars){}

	ft_printf("fodase %d x = %d , y = %d", keycode,x,y);
	
	
	return (0);
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

int main(int ac,char **av)
{
	if(ac == 2)
	{
		char **map;
		map = valid_map_main(av[1]);
		if(map == NULL)
		{
			ft_printf("error");
		}
	}
	else
		ft_printf("nao tem map");

	if(av){}
}


