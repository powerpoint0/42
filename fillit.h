#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"

typedef struct      s_list
{
    int             blockcoords[8];
    char            letter;
    int             x_offset;
    int             y_offset;
    struct s_list   *next;
}                   t_list;

typedef struct      s_main
{
    t_list  *begining_list;
    t_list  *s_list;
    char    letter;
}                   t_main;

#endif
