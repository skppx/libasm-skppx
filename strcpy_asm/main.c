#include <stdio.h>
#include <string.h>

extern size_t ft_strcpy(char *dest, const char *src);

int main()
{
    const char *src = "123456789";
    char dest[20];
    char dest_asm[20];

    strcpy(dest, src);
    ft_strcpy(dest_asm, src);

    printf("dest :%s, dest_asm:%s", dest, dest_asm);

    return 0;
}
