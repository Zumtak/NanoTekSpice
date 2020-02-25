##
## EPITECH PROJECT, 2019
## Makefile for tests
## File description:
## Compile tests with catch2
##

CC = g++

CFLAGS = -W -Wall -Wextra -I../include --coverage

SRC	=	mainTest.cpp \
		testInput.cpp \
		testClock.cpp \
		testTrue.cpp \
		testFalse.cpp \
		testOutput.cpp \
		testComp4001.cpp \
		testComp4011.cpp \
		testComp4030.cpp \
		testComp4069.cpp \
		testComp4071.cpp \
		../src/components/CompInput.cpp \
		../src/components/CompClock.cpp \
		../src/components/CompTrue.cpp \
		../src/components/CompFalse.cpp \
		../src/components/CompOutput.cpp \
		../src/components/Comp4001.cpp \
		../src/components/Comp4011.cpp \
		../src/components/Comp4030.cpp \
		../src/components/Comp4069.cpp \
		../src/components/Comp4071.cpp \
		../src/Pin.cpp \
		../src/Wire.cpp \
		../src/components/1PinComponents.cpp \
		../src/components/14PinsComponents.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME	=	tests

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ:.o=.gcda)
	rm -f $(OBJ:.o=.gcno)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: re all clean fclean
