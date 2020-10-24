//      vectoriel.c
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

// inclure le fichier de prototype des fonctions de la gestion du vecteur
#include "vectoriel.h"


// creer un vecteur 
// paramètre en entrée : taille du vecteur
double *creervecteur(int taille) {
	return calloc(taille,sizeof(double));
}


// additionne les deux vecteurs v1 et v2 
// paramètres les deux vecteurs, la taille
// retourne un nouveau vecteur qu'il faudra libérer
double *addvecteurs(double *v1,double *v2,int taille) {
	// allocation dynamique
	double *resultat = calloc(taille,sizeof(double));
	for(int i=0;i<taille;i+=1) {
		// addition élément par élément
		resultat[i] = v1[i] + v2[i];
	}
	return resultat;
}

// soustrait le premier vecteur du deuxième
// paramètres les deux vecteurs, la taille
// retourne un nouveau vecteur qu'il faudra libérer
double *sousvecteurs(double *v1,double *v2,int taille) {
	// allocation dynamique
	double *resultat = calloc(taille,sizeof(double));
	for(int i=0;i<taille;i+=1) {
		// soustraction élément par élément
		resultat[i] = v1[i] - v2[i];
	}
	return resultat;
}

// multiplie un vecteur pas une constante k
// paramètres le vecteur la constante, la taille
// retourne un nouveau vecteur qu'il faudra libérer
double *prodvecteur(double *v,double k,int taille) {
	// allocation dynamique
	double *resultat = calloc(taille,sizeof(double));
	for(int i=0;i<taille;i+=1) {
		// multiplie chaque élement pas la constante k
		resultat[i] = v[i] * k;
	}
	return resultat;
}

// effectue le produit scalaire de deux vecteurs
// paramètres les deux vecteurs, la taille
// retourne le produit scalaire
double prodscalairevecteur(double *v1,double *v2,int taille) {
	double resultat=0;
	// resultat = S_i(v1(i)*v2(i))
	for(int i=0;i<taille;i+=1) {
		resultat += v1[i] * v2[i];
	}
	return resultat;
}

// affiche le vecteur en ligne
// paramètres le vecteur et la taille
void printvecteur(double *v,int taille) {
	// affichage en ligne
	printf("[");
	for(int i=0;i<taille;i+=1) {
		printf("%.2f ",v[i]);
	}
	printf("]\n");
}

// libération mémoire d'un vecteur
// parametre entree : pointeur vers le vecteur
void liberervecteur(double *ptab) {
	free((void *)ptab);	
}


