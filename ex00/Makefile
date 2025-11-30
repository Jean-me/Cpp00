# Megaphone
NAME = ex00
SRCS = megaphone.cpp
OBJS = $(SRCS:%.c=%.o)
# Compiler
C++ = g++
C++FLAGS = -Wall -Wextra -Werror -std=c++98

# Rules
all: $(NAME)

$(NAME):	$(OBJS) 
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re