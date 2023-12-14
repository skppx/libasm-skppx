NAME	=	libasm.a

CC	=	nasm

CFLAGS	=	-f elf64 -g

SRCS_FILES	=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

OBJS_FILES	=	$(SRCS_FILES:%.s=%.o)

OBJS	=	$(addprefix objs/, $(OBJS_FILES))

all	:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean	:
	rm -rf $(OBJS)
	rm -rf objs/

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

objs/%.o	: srcs/%.s
	mkdir -p objs/
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean fclean re
