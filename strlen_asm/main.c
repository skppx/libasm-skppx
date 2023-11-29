#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *);

int main()
{
    const char *str = "123456789";
    size_t len = strlen(str);
    size_t len_asm = ft_strlen(str);

    printf("len :%zu, len_asm:%zu", len, len_asm);

    return 0;
}
