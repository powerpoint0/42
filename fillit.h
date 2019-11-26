#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"

typedef struct      s_lisst
{
    int             blockcoords[8];
    char            letter;
    int             x_offset;
    int             y_offset;
    struct s_lisst   *next;
}                   t_lisst;

typedef struct      s_main
{
    t_lisst  *begining_list;
    t_lisst  *s_lisst;
    char    letter;
}                   t_main;

t_main  *ft_openreadvalidcoord(int argc, char *c);
t_main  *ft_slash(char *buf,t_main  *s_main);
t_main  *ft_coordsmain();

#endif
