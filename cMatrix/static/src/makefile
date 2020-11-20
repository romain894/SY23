#$@  	Le nom de la cible
#$< 	Le nom de la première dépendance
#$^ 	La liste des dépendances
#$? 	La liste des dépendances plus récentes que la cible
#$* 	Le nom du fichier sans suffixe
#.PHONY: clean mrproper
CC=gcc
AR=ar
#CFLAGS= -Wall  -I../include -fPIC -std=gnu99
CFLAGS= -Wall -I../include -std=gnu99
LDFLAGS=
SRC=$(wildcard *.c)
OBJS= $(SRC:.c=.o)

all: $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

lib:
	$(AR) -cvq ../lib/libmatrices.a $(OBJS)

clean:
	rm *.o
	rm ../lib/libmatrices.a
