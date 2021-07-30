SRC = source/src/
INC = source/inc/
OBJ = build/linux/obj/
BIN = build/linux/bin/
COMPILER = clang++
NAME = sfml
BINARYEXTENSION = .bin
BINARY = $(BIN)$(NAME)$(BINARYEXTENSION)
LIBFLAGS = -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
CPPLINKFLAGS =  $(LIBFLAGS) -O3 -g -o $(BINARY)
CPPCOMPILEFLAGS = -O3 -I $(INC)

defualt: $(OBJ)deps.pch $(OBJ)game.obj $(OBJ)input.obj $(OBJ)player.obj
	$(COMPILER) $(OBJ)deps.pch $(OBJ)game.obj $(OBJ)input.obj $(OBJ)player.obj $(CPPLINKFLAGS)

$(OBJ)deps.pch: $(INC)deps.hpp
	$(COMPILER) -c $(INC)deps.hpp -o $(OBJ)deps.pch $(CPPCOMPILEFLAGS)
$(OBJ)game.obj: $(SRC)game.cpp
	$(COMPILER) -c $(SRC)game.cpp -o $(OBJ)game.obj $(CPPCOMPILEFLAGS)
$(OBJ)input.obj: $(SRC)input.cpp
	$(COMPILER) -c $(SRC)input.cpp -o $(OBJ)input.obj $(CPPCOMPILEFLAGS)
$(OBJ)player.obj: $(SRC)player.cpp
	$(COMPILER) -c $(SRC)player.cpp -o $(OBJ)player.obj $(CPPCOMPILEFLAGS)

clean:
	rm $(OBJ)*.pch $(OBJ)*.obj $(BIN)*(BINARYEXTENSION)