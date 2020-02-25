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
		src/components/CompFalse.cpp \
		src/components/CompTrue.cpp \
		src/components/CompOutput.cpp \
		src/components/CompInput.cpp \
		src/components/CompClock.cpp \
		src/components/Comp4001.cpp \
		src/components/Comp4011.cpp \
		src/components/Comp4030.cpp \
		src/components/Comp4069.cpp \
		src/components/Comp4071.cpp \

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

tests_run:
	cd catch_tests && $(MAKE) && clear && ./tests

.PHONY: re all clean fclean tests_run
