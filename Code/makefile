##################
# Darville Killian et Sinet Théo
# projet : BomberMan
# fichier : makefile, v2
# date : 2022/03/22
##################

CC = g++
CFLAGS = -Wall -ansi
LDFLAGS = #-lm
EXE = System

DEP=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJ =$(SRC: .cpp=.o)

##############################
### regle principale (la 1ere)
all : $(EXE)
			
##############################
### generation des modules objet

principal.o : System.cpp $(DEP)
	$(CC) $(CFLAGS) $< -c
%.o : %.cpp %.h
	$(CC) $(CFLAGS) $< -c


		
##############################
### regle principale : edition de lien
$(EXE) : $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@
	
##############################
### regles complementaires usuelles
.PHONY : clean mrproper

clean : 
	@rm -f *.o
mrproper : clean
	@rm -f *~ a.out $(EXE)
