#$@  	Le nom de la cible
#$< 	Le nom de la première dépendance
#$^ 	La liste des dépendances
#$? 	La liste des dépendances plus récentes que la cible
#$* 	Le nom du fichier sans suffixe
#.PHONY: clean mrproper
CC=gcc
CFLAGS= -Wall  -I../include -fPIC -std=gnu99
SRC=$(wildcard *.c)
OBJS= $(SRC:.c=.o)
all: $(OBJS)
export LD_LIBRARY_PATH=../lib

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

lib:
	$(CC) -shared  -o ../lib/libmatrices.so $(OBJS)

shared-lib:
	    $(CC) -shared -o ../lib/libmatrice.so $(OBJS)

clean:
	rm *.o
	rm ../lib/libmatrices.so
