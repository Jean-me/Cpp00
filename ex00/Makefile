# Megaphone
NAME = ex00
SRCS = ex00.cpp
OBJS = $(SRCS:%.c=%.o)
# Compiler
CC = g++
CFLAGS = -Wall -Wextra -Werror -g

# Rules
all: $(NAME)

$(NAME):	$(OBJS) 
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re