#==========================================================================================

# Makefile for calc_project
#		author: Kurnevich Stanislav

#==========================================================================================

CXX       = g++
WARNINGS  = -Wall -Wextra 

DEBUG_MODE   = -g3 -O0 
RELEASE_MODE = -g0 -O3

VALGRIND_FLAGS = --leak-check=full

CALC_DIR = ./calc
LIBS_DIR = ./libs
	 
SOURCE = $(CALC_DIR)/calc.cpp $(CALC_DIR)/main.cpp $(LIBS_DIR)/Onegin.cpp
OBJECT = $(SOURCE:.cpp=.o)
OUTPUT = Calculator

default: valgrind

valgrind: $(OUTPUT)
	valgrind $(VALGRIND_FLAGS) ./$(OUTPUT) "test"

launch: $(OUTPUT)
	./$(OUTPUT) "test"

$(OUTPUT): $(OBJECT)
	$(CXX) $(WARNINGS) $(DEBUG_MODE) $^ -o $(OUTPUT)

main.o: $(CALC_DIR)/main.cpp
	$(CXX) -c $^

calc.o: $(CALC_DIR)/calc.cpp
	$(CXX) -c $^

Onegin.o: $(LIBS_DIR)/Onegin.cpp
	$(CXX) -c $^
	
clean:
	rm -f *.o *.a $(OBJECT) $(OUTPUT)

#==========================================================================================