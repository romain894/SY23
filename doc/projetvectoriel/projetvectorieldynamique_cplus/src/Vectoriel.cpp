/*
 * Vectoriel.cpp
 * 
 * Copyright 2020 Michel Doussot <michel.doussot@utt.fr>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;
 
#include "Vectoriel.h"

// constructeur vide
// ne créer de vecteur
Vectoriel::Vectoriel() {
	this->taille = 0;
	vecteur = nullptr;
}

// constructeur vecteur sans valeurs
// parametre taille
Vectoriel::Vectoriel(int taille) {
	this->taille = taille;
	vecteur = new double[taille];
}

// constructeur vecteur avec un tableau de valeur
// parametre tableau de valeurs et taille
Vectoriel::Vectoriel(double *valeurs,int taille) {
	this->taille = taille;
	vecteur = new double[taille];
	for(int i=0;i<taille;i+=1) {
		vecteur[i] = valeurs[i];
	}
}

// constructeur de copie
// parametre vecteur non modifié
Vectoriel::Vectoriel(const Vectoriel &V) {
	this->taille = V.getTaille();
	vecteur = new double[taille];
	double *valeurs = V.getValues();
	for(int i=0;i<taille;i+=1) {
		vecteur[i] = valeurs[i];
	}
}

// retourne l'arribut taille
int Vectoriel::getTaille() const {
	return taille;
}

// retourne l'attribut tableau de valeurs
double *Vectoriel::getValues() const {
	return vecteur;
}

// retourne la valeur correspondant à index
double Vectoriel::getValue(int index) const {
	return vecteur[index];
}

// additionne avec un autre vecteur
// parametre deuxième vecteur
void Vectoriel::additionne(const Vectoriel &V) {
	if (V.getTaille() == taille) {
		// allocation dynamique
		double *valeurs = V.getValues();
		for(int i=0;i<taille;i+=1) {
			// addition élément par élément
			vecteur[i] += valeurs[i];
		}	
	}
}

// soustrait avec un autre vecteur
// parametre deuxième vecteur
void Vectoriel::soustrait(const Vectoriel &V) {
	if (V.getTaille() == taille) {
		// allocation dynamique
		double *valeurs = V.getValues();
		for(int i=0;i<taille;i+=1) {
			// soustraction élément par élément
			vecteur[i] -= valeurs[i];
		}
	}
}

// multiplication par une constante
// parametre constante
void Vectoriel::multiplie(double k) {
	for(int i=0;i<taille;i+=1) {
		// multiplication élément par élément par une constante
		vecteur[i]*= k;
	}
}

// produit scalaire avec un autre vecteur
// parametre deuxième vecteur
// retourne le produit scalaire
double Vectoriel::prodscalaire(const Vectoriel &V) const {
	double resultat=0;
	if (V.getTaille() == taille) {
		// resultat = <V1,v2>
		double *valeurs = V.getValues();
		for(int i=0;i<taille;i+=1) {
			resultat += valeurs[i] * vecteur[i];
		}
	}
	return resultat;
}

// surcharge d'opérateurs
// utilise la méthode additionne
// parametre deuxième vecteur
Vectoriel & Vectoriel::operator +=(const Vectoriel &V) {
	additionne(V);
	return *this;
}

// utilise la méthode soustrait
// parametre deuxième vecteur
Vectoriel & Vectoriel::operator -=(const Vectoriel &V) {
	soustrait(V);
	return *this;
}

// accès à un élement du vecteur en lecture
// a droite du symbole d'affectation
// paramètre : index
double Vectoriel::operator [](int index) const {
	return vecteur[index];
}

// accès à un élement du vecteur en écriture
// a gauche du symbole d'affectation
// paramètre : index
double & Vectoriel::operator [](int index) {
	return vecteur[index];
}

// symbole affectation
// clonage de vectoriel avec création d'un nouvel objet
// parametre vecteur source
void Vectoriel::operator=(const Vectoriel &V) { 
	this->taille = V.getTaille();
	vecteur = new double[taille];
	double *valeurs = V.getValues();
	for(int i=0;i<taille;i+=1) {
		vecteur[i] = valeurs[i];
	}
}

// affichage sur le flux de sortie
// cout pour la sortie standard
// parametre  flux de sortie , vecteur
ostream &operator<<(ostream &out,Vectoriel &V) { 
	double *valeurs = V.getValues();
	int longueur = V.getTaille();
    out << "[";
    for(int i=0;i<longueur;i+=1) {
		out << valeurs[i] << " ";
	}
    out << "]";
    return out;
}


Vectoriel::~Vectoriel() {
	delete[] vecteur;
}
