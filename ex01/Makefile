# My Awesome PhoneBook
NAME = ex01
SRCS = My_Awesome_PhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
# Compiler
C++ = c++
C++FLAGS = -Wall -Wextra -Werror -g -std=c++98

# Rules
all: $(NAME)

$(NAME):	$(OBJS) 
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re