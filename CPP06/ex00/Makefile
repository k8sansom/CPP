NAME = convert

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

SRCS = 	main.cpp \
		ScalarConverter.cpp

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