#include "../so_long.h"

int verfic_char_list(char *list,char set)
{
    int i;

    i = -1;
    while (list[++i] != '\0')
    {
        if(list[i] == set)
            return(1);
    }
    return(0);
}

void  flood_fill(char **tab, t_point size, t_point begin,char *list)
{
   
    t_point novas_codenadas;
     tab[begin.y][begin.x] = 'o';
    
    if(begin.y > 0 && verfic_char_list(list, tab[begin.y - 1][begin.x] )== 1 )
    {
        novas_codenadas.x = begin.x;
        novas_codenadas.y = begin.y-1;
        flood_fill(tab,size,novas_codenadas,list);
    }
    if(begin.x > 0 && verfic_char_list(list, tab[begin.y][begin.x -1]) == 1)
    {
        novas_codenadas.x = begin.x-1;
        novas_codenadas.y = begin.y;
        flood_fill(tab,size,novas_codenadas,list);
    }
    if(begin.y < size.y-1 && verfic_char_list(list, tab[begin.y+1][begin.x]) == 1)
    {
        novas_codenadas.x = begin.x;
        novas_codenadas.y = begin.y +1;
        flood_fill(tab,size,novas_codenadas,list);
    }
    if (begin.x < size.x-1 && verfic_char_list(list, tab[begin.y][begin.x+1]) == 1)
    {
        novas_codenadas.x = begin.x + 1;
        novas_codenadas.y = begin.y;
        flood_fill(tab,size,novas_codenadas,list);
    }
}





