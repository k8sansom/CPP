NAME = Intern

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = 	Bureaucrat.cpp \
		AForm.cpp \
		Intern.cpp \
		main.cpp \
		PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \

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