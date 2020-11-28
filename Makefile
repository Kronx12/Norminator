CC=gcc
CFLAGS=-Wall -Wextra -Werror -g3
RM=rm -rf
NAME=norminator

INC=./include/global.h \
	./libft/libft.h
SRCS=	./src/main.c \
		./src/errors.c \
		./src/utils.c \
		./src/parser.c
OBJS=$(SRCS:.c=.o)

LIB=./libft/libft.a

%.c%.o:
	$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(LIB):
	$(MAKE) -C ./libft/

$(OBJS):	$(INC)

$(NAME):	$(INC) $(OBJS) $(LIB)
	$(CC) $(LIB) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re