#ifndef PITTEWAY_H
#define PITTEWAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define MAX 18

extern const int taille_unsigned_long_long;

typedef struct{
	int taille[MAX];
	int indice;
	unsigned long long int nombre[MAX];
}segment;

extern char * puissance(char *,int,int);
extern char * dechiffrage(segment,segment,int);
extern char * pitteway(int,int);
extern void pittest(int,int,segment,segment);
extern char * pitt(int,int);
extern void preuve(void);
extern void droite_br(int,int);
extern void test_temps_pitt_vs_br(void);
extern void test_temps_pitt_vs_pitteway(int,int,int);

#endif
