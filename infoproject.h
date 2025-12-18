#ifndef INFOPROJECT_H_INCLUDED
#define INFOPROJECT_H_INCLUDED
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
//Définir la taille du tableau
#define N 25
#define P 45

//Sous programme qui remplit le tableau par des items
void remplir(char tab[N][P]);

//Sous programme qui efface les items
void effacer(char tab[N][P], int nbpoints);

//Sous programme qui fait tomber et remplir les cases vides
void gravite(char tab[N][P]);

//Sous programme qui inverse deux cases du tableau
char inverser(char tab[N][P], int i, int j, int k, int l);

#endif // INFOPROJECT_H_INCLUDED
