NAME = Form

HEADERS = 	Bureaucrat.hpp \
			Form.hpp \
			RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp \
			ShrubberyCreationForm.hpp

SRCS =  main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re