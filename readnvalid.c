#include "fillit.h"

int ft_numberbonds(char *buf) //kolvo svyazey
{
    char    *tmp;
    int     i;
    int     n;
    char    *a;

    i = 0;
    n = 0;
    tmp = buf;
    while ((a = ft_strchr(tmp, '#')))
    {
        i = 21 - ft_strlen(a); //nomer elementa #
        tmp = &buf[i+1];
        if (buf[i - 5] == '#')
            n++;
        if (buf[i + 5] == '#')
            n++;
        if (buf[i + 1] == '#')
            n++;
        if (buf[i - 1] == '#')
            n++;
    }
    return ((n == 6 || n == 8) ? 0 : -1);
}

int ft_numbersigns(char *buf)  //kolvo # , ft vozvrashaet 0 pri pravilnom rezultate == 4
{
    int i;
    int k;
    int a;

    k = 0;
    a = 0;
    i = 0;
    if(!(buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n' && buf[19] == '\n'))
        return(-1);
    while (buf[i])
    {
        if (buf[i] == '#')
            k++;
        i++;
    }
    if (k != 4)
        return (-1);
    if ((a = ft_numberbonds(buf))!= 0)
            return(-1);
    return(0);
}

int  ft_valid(char   *buf)
{
   int  i;
   int rezalt;

   rezalt = 0;
   i = 0;
   while (buf[i])
   {
       if (buf[i] != '.' || buf[i] != '#' ||  buf[i] != '\n')
           return(-1);
       i++;
   }
   if((rezalt = ft_numbersigns(buf)) != 0)
       return(-1);
   return(0);
}



t_main  *readnvalid(int fd, t_main *s_main)
{
    char    buf[21];
    int     b;
    int p;
    int n;

    b = 0;
    n = 0;
    if (!s_main)
        return(NULL);
    while ((b = read(fd, buf, 21)) > 0 && (buf[b] = 0) && (n < 28))
    {
        if((b != 21 && (p = ft_valid(buf) != 0) && buf[20] != '\n')
                || (b != 20 && (p = ft_valid(buf) != 0)))
            return(NULL);
        else
            ft_slash(buf, s_main);
        n++;
    }
    if (n > 26)
        return (NULL);
    s_main->s_lisst->next = NULL;
    return(s_main);
}

t_main  *ft_openreadvalidcoord(int argc, char *c)
{
    t_main  *inputvalidcoord;
    int     fd;
    t_main  *maain;

    if (argc != 2)
    {
        write(1, "Dear user, fillit needs for 1 argument, enter, please", 53);
        return(NULL);
    }
    fd = open(c, O_RDONLY);
    maain = ft_coordsmain();
    if(fd == -1 || !maain || (!(inputvalidcoord = readnvalid(fd, maain))))
    {
        write(1, "error", 5);
        //ft_freeall(maain);
        return(NULL);
    }
    return(inputvalidcoord);
}