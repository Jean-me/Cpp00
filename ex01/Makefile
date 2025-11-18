# My Awesome PhoneBook
NAME = ex01
SRCS = My_Awesome_PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)
# Compiler
CC = g++
CFLAGS = -Wall -Wextra -Werror -g

# Rules
all: $(NAME)

$(NAME):	$(OBJS) 
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re