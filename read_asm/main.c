#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int ft_read(int fd, void *buf, int byte);

int main()
{

    int fd_asm = open("text.txt", O_RDONLY);
    int len = 12;
    char str[1024];
    char str_asm[1024];
    int res_asm = ft_read(fd_asm, str_asm, len);
    str_asm[len] = 0;
    printf("str_asm: %s\n", str_asm);
    close(fd_asm);
    int fd = open("text.txt", O_RDONLY);
    int res = read(fd, str, len);
    str[len] = 0;
    printf("str: %s\n", str);
    printf("res = %i, res_asm = %i", res, res_asm);
    return (0);
}
