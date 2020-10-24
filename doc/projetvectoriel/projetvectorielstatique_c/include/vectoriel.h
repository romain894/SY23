//      vectoriel.h
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


#ifndef __VECTORIEL_H
#define __VECTORIEL_H


// creer un vecteur sans valeurs
// paramètre en entrée : taille du vecteur
double *creervecteur(int );
// additionne les deux vecteurs v1 et v2 
// paramètres les deux vecteurs, la taille
// retourne un nouveau vecteur qu'il faudra libérer
double *addvecteurs(double *,double *,int );
// soustrait le premier vecteur du deuxième
// paramètres les deux vecteurs, la taille
// retourne un nouveau vecteur qu'il faudra libérer
double *sousvecteurs(double *,double *,int );
// multiplie un vecteur pas une constante k
// paramètres le vecteur la constante, la taille
// retourne un nouveau vecteur qu'il faudra libérer
double *prodvecteur(double *,double ,int );
// effectue le produit scalaire de deux vecteurs
// paramètres les deux vecteurs, la taille
// retourne le produit scalaire
double prodscalairevecteur(double *,double *,int );
// affiche le vecteur en ligne
// paramètres le vecteur et la taille
void printvecteur(double *,int);
// libération mémoire d'un vecteur
// parametre entree : pointeur vers le vecteur
void liberervecteur(double *);

#endif





