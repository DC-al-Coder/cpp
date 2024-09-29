.DEFAULT_GOAL := all

NAME = btc
CC = g++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98

SRCS = main.cpp \
		BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

-include $(DEPS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
