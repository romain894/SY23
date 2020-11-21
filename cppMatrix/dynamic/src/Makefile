#$@  	Le nom de la cible
#$< 	Le nom de la première dépendance
#$^ 	La liste des dépendances
#$? 	La liste des dépendances plus récentes que la cible
#$* 	Le nom du fichier sans suffixe
#.PHONY: clean mrproper
CC=g++
CFLAGS= -Wall  -I../include -fPIC
LDFLAGS=
SRC=$(wildcard *.cpp)
OBJS= $(SRC:.cpp=.o)

all: $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

lib:
	$(CC) -shared  -o ../lib/libmatrix.so $(OBJS)


clean:
	rm *.o
	rm ../lib/libmatrix.so
