##
## EPITECH PROJECT, 2019
## NanoTekSpice
## File description:
## Compile NanoTekSpice
##

CC = g++

CXXFLAGS = -W -Wall -Wextra -Iinclude/

SRC	= 	src/main.cpp \
		src/Pin.cpp \
		src/Wire.cpp \
		src/components/1PinComponents.cpp \
		src/components/14PinsComponents.cpp \
		src/components/16PinsComponents.cpp \
		src/components/24PinsComponents.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CXXFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

%.o: %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

.PHONY: re all clean fclean
