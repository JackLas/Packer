PROG = main.exe

#folders
BIN = bin
HDR = header
SRC = source

#object files
OBJ = 	$(BIN)/main.o \
		$(BIN)/InputManager.o \
		$(BIN)/InputData.o \
		$(BIN)/Packer.o \
		$(BIN)/Application.o

#Compilation flags
FLAGS = -Wall -std=c++14 $(addprefix -I, $(HDR))

#Compile command
COMPILE_COMMAND = g++ $< $(FLAGS) -c -o $@

#final linking
$(PROG): $(OBJ)
	g++ $^ $(FLAGS) -o $@

#object file compilation
$(BIN)/main.o: $(SRC)/main.cpp $(HDR)/Application.hpp
	$(COMPILE_COMMAND)

$(BIN)/InputManager.o: $(SRC)/InputManager.cpp $(HDR)/InputManager.hpp $(HDR)/InputData.hpp
	$(COMPILE_COMMAND)

$(BIN)/InputData.o: $(SRC)/InputData.cpp $(HDR)/InputData.hpp
	$(COMPILE_COMMAND)

$(BIN)/Packer.o: $(SRC)/Packer.cpp $(HDR)/Packer.hpp
	$(COMPILE_COMMAND)

$(BIN)/Application.o: $(SRC)/Application.cpp $(HDR)/Application.hpp $(HDR)/InputManager.hpp $(HDR)/InputData.hpp $(HDR)/Packer.hpp
	$(COMPILE_COMMAND)