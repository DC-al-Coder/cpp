.DEFAULT_GOAL := all

NAME = test
CC = c++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98

SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

-include $(DEPS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)

%.o : %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
