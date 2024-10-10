#include "get_next_line.h"

char *ft_strdup(char *str)
{
    char *dst;
    int i;

    i = 0;
    while (str[i])
        i++;
    dst = (char *)malloc(sizeof(char ) * (i + 1));
    i = 0;
    while (str[i])
    {
        dst[i] = str[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[70000];
    static int buffer_r;
    static int buffer_p;
    int i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (1)
    {
        if (buffer_r <= buffer_p)
        {
            buffer_r = read(fd, buffer,BUFFER_SIZE);
            buffer_p = 0;
            if (buffer_r <= 0)
                break ;
        }
        line[i++] = buffer[buffer_p++];
        if(line[i - 1] =='\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return NULL;
    return (ft_strdup(line));
}