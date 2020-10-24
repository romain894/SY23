//      main.c
//      fichier de test
//      
//      Copyright 2020 Michel Doussot <michel.doussot@utt.fr>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "vectoriel.h"


int main(int argc, char **argv) {
	
	double *v1,*v2,*somme,*diff,*produit,prodscalaire;
	
	
	// creer deux vecteurs non inialises
	v1=creervecteur(3);
	v2=creervecteur(3);
	// v1=[1,3,2]
	v1[0] = 1;
	v1[1] = 3;
	v1[2] = 2;
	// v2=[4,1,6]
	v2[0] = 4;
	v2[1] = 1;
	v2[2] = 6;	
	
	// somme = v1 + v2
	somme=addvecteurs(v1,v2,3);
	// diff = v1 - v2
	diff=sousvecteurs(v1,v2,3);
	// produit = k*v1;
	produit=prodvecteur(v1,2,3);
	// prodscalaire = <v1,v2>
	prodscalaire=prodscalairevecteur(v1,v2,3);
	// affichage des résultats
	printvecteur(v1,3);
	printvecteur(v2,3);
	printvecteur(somme,3);
	printvecteur(diff,3);
	printvecteur(produit,3);
	printf("produit scalaire %.2f\n",prodscalaire);
	
	// libération de la mémoire allouée aux vecteurs
	liberervecteur(v1);
	liberervecteur(v2);
	liberervecteur(somme);
	liberervecteur(diff);
	liberervecteur(produit);

      
	return EXIT_SUCCESS;
}

