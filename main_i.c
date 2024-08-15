
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
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 100, 100, "Hello world!");
	//mlx_loop(mlx);
	img.img = mlx_new_image(mlx, 100, 100);


	img.addr = mlx_get_data_addr(img.img,&img.bits_per_pixel,&img.line_length,&img.endian);

	int x;
	int y ;

	 x = 5;
	 y = 50;

	char *offset;
	 offset = img.addr + (y * img.line_length + 5 * (img.bits_per_pixel / 8));
	*(unsigned int*)offset =  0x00FF0000;

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	sleep(1);

	offset = img.addr + (y * img.line_length + 10 * (img.bits_per_pixel / 8));
	*(unsigned int*)offset =  0x00FF0000;
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	sleep(2);

	offset = img.addr + (y * img.line_length + 15 * (img.bits_per_pixel / 8));
	*(unsigned int*)offset =  0x00FF0000;
	
	//my_mlx_pixel_put(&img,5,6,0x00FF0000);
	// mlx_hook()
	// mlx_key_hook()
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_loop(mlx);
	mlx_destroy_image(mlx,img.img);
	
	//mlx_do_sync();
	sleep(1);
	
	mlx_destroy_window(mlx,mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}