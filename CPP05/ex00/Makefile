NAME = Bureaucrat

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = 	Bureaucrat.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re