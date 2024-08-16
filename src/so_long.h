
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

typedef struct s_imgs {
	int		width;
	int		height;
	void*	img;
}				 t_imgs;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char 	**map;
	t_imgs 	imgs[5];
}				t_vars;


void  flood_fill(char **tab, t_point size, t_point begin,char *list);

int ft_ponter_len(char **map);
 /**
  * @brief return len of the ponter_ponter
  * @param map or str or array of the array
  * @return valuse of de map [max]
 */

int	key(int keycode, t_vars *vars );


t_point locat_player(char **map);
/**
* @brief locate player
* @param map the game
* @return x and y locat player
*/

//  #####=map_functions_ imgs=#####

	t_imgs* img_set(t_vars vars,t_imgs* imgs);
	/**
	 * @brief define  imgs
	 * @param vars variabes  of th work th window
	 * @param imgs save the imgs variabel.
	 * @return array with imgs definde
	*/
	void img_free(t_vars vars,t_imgs *imgs);
	/**
	 * @brief dystory the imgs
	 * @param vars variabes  of th work th window
	 * @param imgs save the imgs variabel.
	 * @return array with imgs definde
	*/
	void render_imgs(t_vars vars, t_imgs *imgs,char **map);
	/**
	 * @brief set imgs in window
	 * @param vars variabes  of th work th window
	 * @param imgs save the imgs variabel.
	 * @param map word of the game.
	*/
	void map_in_img(char **map,t_vars *vars);
	/**
	 * @brief mange imgs
	 * @param vars variabes  of th work th window
	 * @param map word of the game
	*/


//  #####=END=#####


//  #####=map_functions_ whindows=#####


	t_point window_size(char** map);
	/**
	 * @brief calcule width and height of the window
	 * @return t_point struct with x and y the window
	*/

	void window_start(char **map_copy);
	/**
	 * @brief function create the windo and startd game
	 * @param map_copy - copy the map returnde of the validated
	*/

//  #####=END=#####



//  #####=map_functions_ map=#####

void map_print(char **map);
/**
 * @brief print map in terminal
 * @param map array the map
*/

char **aloc_map(int len , char *url);
/**
* @brief alloc memory for map
* @param map pointer for map 
* @return map of the memory aloced
*/

char** map_free(char **map);
/**
* @brief free memory for map
* @param map pointer for map 
* @return NULL
*/

char **valid_map_main(char *url);
/**
* @brief start validaeted map
* @param url str with paht for map
* @return NULL or map
*/

char **valid_maps_unes(char **map,int len);
/**
* @brief  validaeted map frame and chek EPC and ckek pah of the coletbas = C
* @param map creat map use the aloc_map
* @param len Number of the lines in y the map 
* @return NULL or map
*/

int locat_colt(char **map);
/**
 * @brief valid EPC
 * @param map
 * @return 0 or 1 
*/

//  #####=END=#####


#endif