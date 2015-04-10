#include <stdio.h>
#include "Estocolmo.h"

int numeroEstocolmo(int n){
	int i;
	int contador = 0;
	for(i = 30 ; i>=0 ; i--)
		if(n & (1<<i))
			contador++;
	if(contador % 2 == 0)
		return 1;
	if(contador % 2 == 1)
		return 0;
}


int estocolmo(int v){
	int n = v*2;
	if(numeroEstocolmo(n) == 1)
		return n;
	else
		return n+1;

}

int numeroEstocolmoCadena(unsigned char * bits, int nbytes){
	int contador = 0;
	int bites = nbytes * 8;
	int i;
	int j;
	for (i=0; i < nbytes; ++i){
		unsigned char num = bits[i];
		for (j=0; j < 8; j++){
			if(num & (1<<i))
				contador++;
		}
	}
	if(contador % 2 == 0)
		return 1;
	if(contador % 2 == 1)
		return 0;
}

int main(int argc, char const *argv[]){
	int p;
	printf("Introduce el i-esimo numero que quieres saber:\n");
	scanf("%d",&p);
	printf("%d",estocolmo(p));
	printf("\n");
	return 0;
}