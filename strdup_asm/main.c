#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//extern size_t   ft_strcpy(char *dest, const char *src);
extern char     *ft_strdup(const char *s);
extern char		*ft_strcpy(char *, char *);
extern int		ft_strlen(char *);

int main()
{
    const char *src = "Hello assembly!";
    //char *str = strdup(src);
    char *str_asm = ft_strdup(src);
    printf("str_asm:%s",str_asm);
   // free(str);
    //free(str_asm);

    return 0;
}
