#include <stdio.h>
#include <string.h>

extern size_t ft_strcmp(const char *s1, const char *s2);

int main()
{
    const char *s1 = "hello";
    const char *s2 = "hello";

    int res = strcmp(s1, s2);
    int res_asm = ft_strcmp(s1, s2);

    printf("res :%i, res_asm:%i", res, res_asm);

    return 0;
}
