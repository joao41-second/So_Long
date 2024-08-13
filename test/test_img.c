
#include "./minilibx-linux/mlx_int.h"
#include "./minilibx-linux/mlx.h"
# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void *img;
	//t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	//mlx_loop(mlx);
	//img.img = mlx_new_image(mlx, 100, 100);

	int		img_width;
	int		img_height;
	
	int x;
	int y ;

	 x = 1000;
	 y = 1000;


	img = mlx_xpm_file_to_image(mlx,"./img/Untitled.xpm",&img_width,&img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	//sleep(2);
	mlx_put_image_to_window(mlx, mlx_win, img, 50, 0);

	

	mlx_destroy_image(mlx,img);
	
	//mlx_loop(mlx);

	sleep(5);
	mlx_destroy_window(mlx,mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}




