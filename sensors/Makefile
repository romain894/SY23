#$@  	Le nom de la cible
#$< 	Le nom de la première dépendance
#$^ 	La liste des dépendances
#$? 	La liste des dépendances plus récentes que la cible
#$* 	Le nom du fichier sans suffixe
#.PHONY: clean mrproper
export MAKE=make
LISTE=`ls`

all:
	@for i in $(LISTE); do \
		if test -d $$i; then \
		  echo "all $$i"; \
		 if test -e $$i/Makefile; then \
		   echo "make -C  $$i "; \
		   $(MAKE) -C  $$i ; \
		  else \
		   echo "WARNING $$i/Makefile" ;\
		 fi; \
		fi; \
	done  

	
mrproper: clean

clean:
	@for i in $(LISTE); do \
		if test -d $$i; then \
		  echo "clean $$i"; \
		 if test -e $$i/Makefile; then \
		   echo "make -C  $$i clean"; \
		   $(MAKE) -C  $$i clean ; \
		  else \
		   echo "WARNING $$i/Makefile" ;\
		 fi; \
		fi; \
	done  
