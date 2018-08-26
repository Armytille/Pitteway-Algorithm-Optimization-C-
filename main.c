#include "pitteway.h"

/*La taille d'un unsigned long long int, 64 sur la plupart des machines*/
const int taille_unsigned_long_long = (int)(8*sizeof(unsigned long long int));

int main (void){
	//segment t,d;
	//preuve();
	//pittest(11,3,t,d);
 	test_temps_pitt_vs_br();
	//test_temps_pitt_vs_pitteway(11, 3, 1000000);
	return 0;
}
