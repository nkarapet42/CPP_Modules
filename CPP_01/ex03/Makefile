NAME = sparta

HEADERS =   HumanA.hpp \
			HumanB.hpp \
			Weapon.hpp

SRCS =  main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

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