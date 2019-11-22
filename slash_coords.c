#include "fillit.h"
void    ft_freeall(t_main  *s_main)
{
    while (s_main->s_list)
    {
        // ft ochistki vsey structury s_main
    }
}

t_main  *ft_coordsmain()    // sozdayu structuru s_main
{
    t_main  *s_main;
    t_list  *s_list;
    char    letter;

    letter = 'A';
    if (!(s_main = (t_main *)malloc(sizeof(t_main))))
        return (NULL);
    s_main->begining_list = s_list;
    s_main->s_list = s_list;
    s_main->letter = letter;
    return(s_main);
}

t_main  *ft_coord_one_tetramino(char *buf,int x_min,int y_min,t_main *s_main)
{
    int     n;
    char    *a;
    t_list  *tmp;

    n = 0;
    a = &buf;
    if (!(s_main->s_list = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    while (a = ft_strchr(a, '#') != NULL)))
    {
        i = 21 - ft_strlen(a); //nomer elementa #
        a++;
        x = i % 5 - x_min;
        y = i / 5 - y_min;
        s_main->s_list->blockcoords[n++] = x;
        s_main->s_list->blockcoords[n++] = y;
    }
    s_main->s_list->letter = s_main->letter;
    s_main->letter++;
    s_main->s_list = s_main->s_list->next;
    return(s_main);
}

t_main  *ft_slash(char *buf,t_main  *s_main) //na skolko mozhno sdvinut vverh i vlevo
{
    int i;
    int y_min;
    int n;
    t_main *a;

    i = 0;
    while (buf[i] != '#')
        i++;
    y_min = i / 5;
    i = 0;
    while (buf[i] != '#')
    {
        if (i >= 15 && n = 0)
        {
            n++;
            i = 0;
        }
        i = n + i + 5;
    }
    a = ft_coord(buf, i % 5, y_min, s_main);
    return (a);
}
