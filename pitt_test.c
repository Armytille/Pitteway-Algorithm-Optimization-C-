#include "pitteway.h"

void preuve(void){ // compare les résultats de pitt et pitteway.
	int i,j;

	for(i=10;i<50;i++)
		for(j=1;j<10;j++)
			if(strcmp(pitt(i,j),pitteway(i,j)) != 0){
				printf ("u : %d , v : %d \n",i,j);
				return;
			}
	printf ("Les résultats entre pitt et pitteway sont identiques !\n");
	return;
}

void test_temps_pitt_vs_br(){

	int i,j;
	segment t, d;
	clock_t temps = clock();

	for(i = 1;i<1024;i++)
		for(j = 1;j<i;j++)
			pittest(i,j,t,d);
		printf("Temps de calcul en seconde pour la fonction pittest   : %Lf\n",(long double)((clock()-temps) / (long double)CLOCKS_PER_SEC));
	temps = clock();
	for(i = 1;i<1024;i++)
		for(j = 1;j<i;j++)
			droite_br(i,j);
	printf("Temps de calcul en seconde pour la fonction droite_br : %Lf\n",(long double)((clock()-temps) / (long double)CLOCKS_PER_SEC));
}

void test_temps_pitt_vs_pitteway(int u, int v, int nb_it){

	int i;
	char *res,*res2;
	clock_t temps = clock();

	for(i = 0;i<nb_it;i++){
		res = pitt(u,v);
		free(res);
	}
	printf("Temps de calcul en seconde pour la fonction pitt    : %Lf\n",(long double)((clock()-temps) / (long double)CLOCKS_PER_SEC));
	temps = clock();
	for(i = 0;i<nb_it;i++){
		res2 = pitteway(u,v);
		free(res2);
	}
	printf("Temps de calcul en seconde pour la fonction pitteway : %Lf\n",(long double)((clock()-temps) / (long double)CLOCKS_PER_SEC));
}
