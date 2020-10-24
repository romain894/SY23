/*
 * main.cpp
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

int main(int argc, char **argv){
	
	Vectoriel v1(3);
	Vectoriel v2(3);
	// v1=[1,3,2]
	v1[0] = 1;
	v1[1] = 3;
	v1[2] = 2;
	cout << v1 << endl;
	//sauvegardes de v1 pour les calculs
	Vectoriel v3=v1;
	Vectoriel v4=v1;
	// v2=[4,1,6]
	v2[0] = 4;
	v2[1] = 1;
	v2[2] = 6;	
	cout << v2 << endl;
	// v1+v2 -> v1
	v1 += v2;
	cout << v1 << endl;
	// v3-v2 -> v3
	v3 -= v2;
	cout << v3 << endl;
	// scalaire=<v4,v2>
	double scalaire=v4.prodscalaire(v2);
	cout << "produit scalaire <" << v4 << "," << v2 << "> = " << scalaire << endl;
	return EXIT_SUCCESS;
}

