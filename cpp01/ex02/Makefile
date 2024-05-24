.DEFAULT_GOAL := all

NAME = test
CC = c++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)

%.o : %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
