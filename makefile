# Copy and adapt the contents of a makefile here.
# Use separate compilation, support "make clean", and name your 
# executable "fans" as per the specification
COURSE = CS240
SEMESTER = spring2022

# Update the CP_NUMBER if you adapt this makefile for future assignments
CP_NUMBER = 5

# Change the following to your own information
LASTNAME = Turgay
GITUSERID = MrBoris1

EXE = main

# Name files according to CS240 naming conventions
REPODIR = ../$(COURSE)-CP$(CP_NUMBER)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Player.o $(OBJ)/main.o $(OBJ)/PlayerNode.o $(OBJ)/Hash.o
	$(CC) $(FLAGS) $(OBJ)/Player.o $(OBJ)/main.o $(OBJ)/PlayerNode.o $(OBJ)/Hash.o -o $@

$(OBJ)/main.o: main.cpp Parser.h 
	$(CC) $(FLAGS) -c main.cpp -o $@

$(OBJ)/Hash.o: Hash.cpp Hash.h
	$(CC) $(FLAGS) -c Hash.cpp -o $@

$(OBJ)/Player.o: Player.cpp Player.h
	$(CC) $(FLAGS) -c Player.cpp -o $@

$(OBJ)/PlayerNode.o: PlayerNode.cpp PlayerNode.h BST.h
	$(CC) $(FLAGS) -c PlayerNode.cpp -o $@


# fans: fans.cpp Binary_Tree.h DLL.h fans.h Email.h phone.h g++ -Wall -Wextra -g fans.cpp Email.cpp phone.cpp -o bin/fans

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz

