#include "pitteway.h"

char * puissance(char * str,int nb,int alloc){

	int i,j,taille = strlen(str);
	
	if(alloc){
		str = realloc(str,nb * taille* sizeof(*str)+1);
		assert(str);
	}
	for(i=1;i<nb;i++)
		for(j=0;j<taille;j++)
			str[j+taille*i] = str[j];
	return str;
}
char * dechiffrage(segment a,segment b,int nb){
	
	char *res = malloc(nb * (a.taille[0]+b.taille[0]) * sizeof(*res)+1); // On alloue directement la bonne taille comme ça on évite le realloc dans la fonction puissance.
	int i = 0;

	assert(res);
	do{
		res[i++]= '0' + (a.nombre[0] & 1);
		a.nombre[0] >>= 1;
	}
	while(a.nombre[0]);

	do{
		res[i++]= '0' + (b.nombre[0] & 1);
		b.nombre[0] >>= 1; 
	}
	while(b.nombre[0]);
	return res;
}

char * pitteway(int u,int v){

	char t[50],d[50],*tmp;
 	tmp = malloc(100* sizeof(*tmp)); //leeeeeeeent

	t[0] = '1';
	t[1] = '\0';
	d[0] = '0';
	d[1] = '\0';
	tmp[0] = '\0';
	u -= v;
	while(u != v){
		if(u > v){
			u -= v;
			strcat(tmp,d);
			strcat(tmp,t);
			memcpy(t,tmp,strlen(tmp)+1);
			tmp[0] = '\0';
		}
		else{
			v -= u;
			strcat(tmp,d);
			strcat(tmp,t);
			memcpy(d,tmp,strlen(tmp)+1);
			tmp[0] = '\0';
		}
	}
	strcat(tmp,d);
	if(u>1)
		return puissance(strcat(tmp,t),u,1);
	else
		return strcat(tmp,t);
}

char * pitt(int u,int v){

	segment t,d;

	t.taille[0] = t.nombre[0] = d.taille[0] = 1;
	d.nombre[0] = 0;
	u -= v;
	while(u != v){
		if(u > v){
			u -= v;
			t.nombre[0] <<= d.taille[0];
			t.taille[0] += d.taille[0];
			t.nombre[0] += d.nombre[0];
		}
		else{
			v -= u;
			d.taille[0] += t.taille[0];
			d.nombre[0] += t.nombre[0]<<(d.taille[0]-t.taille[0]);
		}
	//printf ("t=%llu d=%llu t.taille=%d d.taille=%d u = %d v = %d\n",t.nombre,d.nombre,t.taille,d.taille,u,v);
	}
	return (u>1) ? puissance(dechiffrage(d,t,u),u,0) : dechiffrage(d,t,u);

}
