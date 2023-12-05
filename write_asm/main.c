#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern int ft_write(int fd, void *buf, int byte);

int main()
{
    char str[] = "hello world!";
    int len = strlen(str);
    int res_asm = ft_write(1, str, len);
    printf("\n");
    int res = write(1, str, len);
    printf("\nres = %i, res_asm = %i", res, res_asm);
    return (0);
}
