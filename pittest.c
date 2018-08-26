#include "pitteway.h"

/*La fonction principale de ce projet, elle calcule un segment de droite*/
void pittest(int u,int v,segment t,segment d){

	int i;
/*Initialisation des variables*/
	for(i = 0;i<MAX;i++){
		t.nombre[i] = 0;
		d.nombre[i] = 0;
		t.taille[i] = d.taille[i] = 1;	
	}
	t.nombre[0] = 1;
	t.indice = d.indice = 0;
	u -= v;
	while(u != v){
		if(u > v){
			u -= v;
			/*On verifie qu'on va pouvoir stocker notre nombre dans un unsigned long long int*/
			if(t.taille[t.indice]+d.taille[d.indice] > taille_unsigned_long_long){
				/*Si on rentre ici c'est qu'on ne peut pas le stocker, on va donc le stocker dans un endroit libre du tableau*/
				t.indice++;
				t.taille[t.indice] = d.taille[d.indice]; 
				t.nombre[t.indice] += d.nombre[d.indice];
				continue;
			}
			/*On peut stocker notre nombre donc on va le fabriquer ici*/
			t.nombre[t.indice] <<= d.taille[d.indice];
			t.taille[t.indice] += d.taille[d.indice];
			t.nombre[t.indice] += d.nombre[d.indice];

		}
		else{
			v -= u;
			if(t.taille[t.indice]+d.taille[d.indice] > taille_unsigned_long_long){
				d.indice++;
				d.taille[d.indice] = t.taille[t.indice];
				d.nombre[d.indice] = t.nombre[t.indice];
				continue;
			}
			d.taille[d.indice] += t.taille[t.indice];
/*(d.taille[d.indice]-t.taille[t.indice]) est négatif dans beaucoup de cas, "<<" n'a donc aucun effet, si l'expression devient positive c'est que la taille n'est pas correcte et "<<" corrige alors le tir*/
			d.nombre[d.indice] += t.nombre[t.indice]<<(d.taille[d.indice]-t.taille[t.indice]);
		}
	}
/*Pour decomposer*/
#if 0
	do{
		do{
			printf("%llu",d.nombre[d.indice] & 1);
			d.nombre[d.indice] >>= 1;
			d.taille[d.indice]--;
		}
		while(d.taille[d.indice]);
	}
	while(d.indice--);

	do {
		do{
			printf("%llu",t.nombre[t.indice] & 1);
			t.nombre[t.indice] >>= 1;
			t.taille[t.indice]--;
		}
		while(t.taille[t.indice]);
	}
	while(t.indice--);
	printf("\n");
#endif
}

void droite_br (int u, int v) {
   int x, y, delta, incD, incH;

   incH   = v << 1;
   delta  = incH - u;
   incD   = delta - u;
   for (x = 0, y = 0; x <= u; x++) {
     // affiche(x, y);
      if (delta > 0) {
         y++;
         delta += incD;
      }
      else {
         delta += incH;
      }
   }
}
