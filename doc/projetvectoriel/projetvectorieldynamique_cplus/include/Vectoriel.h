/*
 * Vectoriel.h
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

#ifndef __VECTORIEL_H
#define __VECTORIEL_H

#include <ostream>

using namespace std;

// classe Vectoriel qui permet de gérer les opérations de base sur les vecteurs
class Vectoriel {
	
  private :
	
	double *vecteur; // contenu du vecteur
	int taille; // taille du vecteur
	
  public:
	// constructeur vide
	// ne créer de vecteur
	 Vectoriel();
	// constructeur vecteur sans valeurs
	// parametre taille
	Vectoriel(int );
	// constructeur vecteur avec un tableau de valeur
	// parametre tableau de valeurs et taille
	Vectoriel(double *,int );
	// constructeur de copie
	// parametre vecteur non modifié
	Vectoriel(const Vectoriel &);
	
	// retourne l'arribut taille
	int getTaille() const;
	// retourne l'attribut tableau de valeurs
	double *  getValues() const ;
	// retourne la valeur correspondant à index
	double getValue(int index) const ;
	// opérations avec un autre vecteur
	// additionne avec un autre vecteur
	// parametre deuxième vecteur
	void additionne(const Vectoriel &);
	// soustrait avec un autre vecteur
	// parametre deuxième vecteur
	void soustrait(const Vectoriel &);
	// multiplication par une constante
	// parametre constante
	void multiplie(double );
	// produit scalaire
	// resultat = <v1,v2>
	// parametre deuxième vecteur (nommé v2)
	// retourne le produit scalaire
	double prodscalaire(const Vectoriel &) const;
	
	// surcharge d'opérateurs
	// utilise la méthode additionne
	// parametre deuxième vecteur
	Vectoriel & operator +=(const Vectoriel &) ;
	// utilise la méthode soustrait
	// parametre deuxième vecteur
	Vectoriel & operator -=(const Vectoriel &) ;
	// accès à un élement du vecteur en lecture
	// a droite du symbole d'affectation
	// paramètre : index
	double operator [](int) const;
	// accès à un élement du vecteur en écriture
	// a gauche du symbole d'affectation
	// paramètre : index
	double & operator [](int );
	// symbole affectation
	// clonage de vectoriel avec création d'un nouvel objet
	// parametre vecteur source
	void operator=(const Vectoriel &);
	// affichage sur le flux de sortie
	// cout pour la sortie standard
	// parametre  flux de sortie , vecteur
	friend ostream &operator<<(ostream &,Vectoriel &) ;
	// destructeur
	~Vectoriel();
};


#endif




