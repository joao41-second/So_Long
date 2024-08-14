
#ifndef SO_LONG_H
#define SO_LONG_H


#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/Get_next_line/get_next_line_bonus.h"


typedef struct  s_point
{
int           x;
int           y;
}               t_point;




char **valid_map_main(char *url);

char **valid_maps_unes(char **map,int len);

int verfic_char_list(char *list,char set);

void map_print(char **map);

void  flood_fill(char **tab, t_point size, t_point begin,char *list);

#endif