#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_list
{
    void    *data;
    struct s_list *next;
}        t_list;

int        ft_strlen(char *str);
char    *ft_strcpy(char *dest, char *src);
int        ft_strcmp(const char *dest, const char *src);
ssize_t    ft_write(int fd, const void *buf, size_t count);
ssize_t    ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s);

#endif
