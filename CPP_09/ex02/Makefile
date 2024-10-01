NAME = PmergeMe

HEADERS = PmergeMe.hpp

SRCS =  main.cpp \
		PmergeMe.cpp

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

test: $(NAME)
	$(eval ARG = $(shell jot -r 3000 1 5000))
	./PmergeMe $(ARG)

re: fclean all 

.PHONY: all clean fclean re test