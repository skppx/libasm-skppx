#include "lib.h"

void	test_ft_strdup()
{
	printf("\033[1m");
	printf("\t--- TEST FT_STRDUP ---\n\n");
	printf("\033[0m");

	char *str = "coucou";
	char *ret;
	char *ret2;

	printf("str = '%s'\n", str);
	ret = ft_strdup(str);
	printf("ft_strdup = %s\n", ret );
	ret2 = strdup(str);
	printf("rl_strdup = %s\n", ret2 );
	printf("\n");
	free(ret);
	free(ret2);

	str = "toto";
	printf("str = '%s'\n", str);
	ret = ft_strdup(str);
	ret2 = strdup(str);
	printf("ft_strdup = %s\n", ret);
	printf("rl_strdup = %s\n", ret2);
	printf("\n");
	free(ret);
	free(ret2);

	str = "coucou comment ca va ?";
	printf("str = '%s'\n", str);
	ret = ft_strdup(str);
	ret2 = strdup(str);
	printf("ft_strdup = %s\n", ret);
	printf("rl_strdup = %s\n", ret2);
	printf("\n\n");
	free(ret);
	free(ret2);
	
    str = "123456789";
	printf("str = '%s'\n", str);
	ret = ft_strdup(str);
	ret2 = strdup(str);
	printf("ft_strdup = %s\n", ret);
	printf("rl_strdup = %s\n", ret2);
	printf("\n\n");
	free(ret);
	free(ret2);
}

void	test_ft_read(void)
{
	printf("\033[1m");
	printf("\t--- TEST FT_READ ---\n\n");
	printf("\033[0m");

	{
		printf("\ttest with file : Makefile\n\n");
		int		fd = open("Makefile", 0);
		char	ft_str[102];
		char	rl_str[102];
		printf("retour de ft_read: %zd\n", ft_read(fd, ft_str, 100));
        perror("errno :");
		ft_str[100] = '\0';
		printf("%s\n", ft_str);
		close(fd);
		fd = open("Makefile", 0);
		printf("retour de read: %zd\n", read(fd, rl_str, 100));
        perror("errno :");
		rl_str[100] = '\0';
		printf("%s\n", rl_str);
		close(fd);
		printf("\n\n");
	}
	{
		printf("\ttest with file : empty\n\n");
		int		fd = open("empty", 0);
		char	ft_str[102];
		char	rl_str[102];
		printf("retour de ft_read: %zd\n", ft_read(fd, ft_str, 100));
        perror("errno :");
		ft_str[101] = '\0';
		printf("%s\n", ft_str);
		close(fd);
		fd = open("empty", 0);
		printf("retour de read: %zd\n", read(fd, rl_str, 100));
        perror("errno :");
		rl_str[101] = '\0';
		printf("%s\n", rl_str);
		close(fd);
		printf("\n\n");
	}
	{
		printf("\ttest with file : existepas\n\n");
		int		fd = open("existepas", 0);
		char	ft_str[102];
		char	rl_str[102];
		printf("retour de ft_read: %zd\n", ft_read(fd, ft_str, 100));
        perror("errno :");
		ft_str[101] = '\0';
		printf("%s\n", ft_str);
		//close(fd);
		fd = open("existepas", 0);
		printf("retour de read: %zd\n", read(fd, rl_str, 100));
        perror("errno :");
		rl_str[101] = '\0';
		printf("%s\n", rl_str);
		//close(fd);
		printf("\n\n");
	}
}

void	test_ft_write(void)
{
	printf("\033[1m");
	printf("\t--- TEST FT_WRITE ---\n\n");
	printf("\033[0m");
	{
		printf("\033[1m");
		printf("str = \"\"\n");
		printf("\033[0m");
		printf(" <- retour de write - ft_write: %zd\n", ft_write(1, "", 0));
        perror("errno : ");
		printf(" <- retour de write - rl_write: %zd\n", write(1, "", 0));
        perror("errno : ");
		printf("\n\n");
	}
	{
		char *str = "salut salut 42 ca va ?";
		printf("\033[1m");
		printf("str = %s\033[0m\n", str);
		printf(" <- retour de write - ft_write: %zd\n", ft_write(1, str, ft_strlen(str)));
        perror("errno : ");
		printf(" <- retour de write - rl_write: %zd\n", write(1, str, ft_strlen(str)));
        perror("errno : ");
		printf("\n\n");
	}
	{
		char *str = "TEST fd pas bon !!!";
		printf("\033[1m");
		printf("str = %s\n", str);
		printf("\033[0m");
		printf(" <- retour de write - ft_write: %zd\n", ft_write(-43, str, ft_strlen(str)));
        perror("errno : ");
		printf(" <- retour de write - rl_write: %zd\n", write(-43, str, ft_strlen(str)));
        perror("errno : ");
		printf("\n\n");
	}
}

void	test_ft_strcmp()
{
	printf("\033[1m");
	printf("\t--- TEST FT_STRCMP ---\n\n");
	printf("\033[0m");

	{
		char *dest = "\xff";
		char *src = "\xff\xff";
		printf("str = '%s'\n", dest);
		printf("str2 = '%s'\n", src);
		printf("ft_strcmp = %d\n", ft_strcmp(dest, src));
		printf("rl_strcmp = %d\n", strcmp(dest, src));
		printf("\n\n");
	}
	{
		const char dest1[] = "";
		const char src[] = "";
		printf("str = '%s'\n", dest1);
		printf("str2 = '%s'\n", src);
		printf("ft_strcmp = %d\n", ft_strcmp("", ""));
		printf("rl_strcmp = %d\n", strcmp("", ""));
		printf("\n");
	}
	{
		char *dest2 = "aca";
		char *src = "acab";
		printf("str = '%s'\n", dest2);
		printf("str2 = '%s'\n", src);
		printf("ft_strcmp = %d\n", ft_strcmp(dest2, src));
		printf("rl_strcmp = %d\n", strcmp(dest2, src));
		printf("\n\n");
	}
	{
		char dest2[] = "11";
		char *src = "1";
		printf("str = '%s'\n", dest2);
		printf("str2 = '%s'\n", src);
		printf("ft_strcmp = %d\n", ft_strcmp(dest2, src));
		printf("rl_strcmp = %d\n", strcmp(dest2, src));
		printf("\n\n");
	}
	{
		char dest2[] = "11";
		char *src = "111";
		printf("str = '%s'\n", dest2);
		printf("str2 = '%s'\n", src);
		printf("ft_strcmp = %d\n", ft_strcmp(dest2, src));
		printf("rl_strcmp = %d\n", strcmp(dest2, src));
		printf("\n\n");
	}
}

void	test_ft_strcpy()
{
	printf("\033[1m");
	printf("\t--- TEST FT_STRCPY ---\n\n");
	printf("\033[0m");

	{
		char dest[20];
		char *src = "9876";
		printf("str = '%s'\n", dest);
		printf("str2 = '%s'\n", src);
		printf("ft_strcpy = %s\n", ft_strcpy(dest, src));
		printf("rl_strcpy = %s\n", strcpy(dest, src));
		printf("\n");
	}
	{
		char dest1[20];
		char *src = "toto";
		printf("str = '%s'\n", dest1);
		printf("str2 = '%s'\n", src);
		printf("ft_strcpy = %s\n", ft_strcpy(dest1, src));
		printf("rl_strcpy = %s\n", strcpy(dest1, src));
		printf("\n");
	}
	{
		char dest2[20] = "test3";
		char *src = "salut42";
		printf("str = '%s'\n", dest2);
		printf("str2 = '%s'\n", src);
		printf("ft_strcpy = %s\n", ft_strcpy(dest2, src));
		printf("rl_strcpy = %s\n", strcpy(dest2, src));
		printf("\n\n");
	}
}

void	test_ft_strlen()
{
	printf("\033[1m");
	printf("\t--- TEST FT_STRLEN ---\n\n");
	printf("\033[0m");

	char *str = "";
	printf("str = '%s'\n", str);
	printf("ft_strlen = %d\n", ft_strlen(str));
	printf("rl_strlen = %lu\n", strlen(str));
	printf("\n");

	str = "toto";
	printf("str = '%s'\n", str);
	printf("ft_strlen = %d\n", ft_strlen(str));
	printf("rl_strlen = %lu\n", strlen(str));
	printf("\n");

	str = "coucou comment ca va ?";
	printf("str = '%s'\n", str);
	printf("ft_strlen = %d\n", ft_strlen(str));
	printf("rl_strlen = %lu\n", strlen(str));
	printf("\n\n");
}

int main()
{
	test_ft_strcmp();
//    test_ft_strlen();
//    test_ft_strcpy();
//    test_ft_write();
//	test_ft_read();
//	test_ft_strdup();

	//printf("%d\n", ft_atoi_base("-+g--2a", "0123456789abcdef"));
//	printf("%d\n", ft_atoi_basec("-+g--2a", "0123456789abcdef"));
	return (0);
}
