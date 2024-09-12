NAME =  Interface

HEADERS =   AMateria.hpp \
			ICharacter.hpp \
			MateriaSource.hpp \
			IMateriaSource.hpp \
			Character.hpp \
			Ice.hpp \
			Cure.hpp

SRCS =  main.cpp \
		AMateria.cpp \
		MateriaSource.cpp \
		Character.cpp \
		Ice.cpp \
		Cure.cpp 

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