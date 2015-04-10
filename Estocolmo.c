#include <stdio.h>
#include "Estocolmo.h"

/**
 *Funcion que verifica si un numero es de la serie de Estocolmo
 *var: int n numero a verificar si es de la serie de Estocolmo
 *return 1 si el numero es de Estocolmo
 *return 0 si el numero no es de Estocolmo 
*/
int numeroEstocolmo(int n){
	//Iterador para recorrer los bits del numero
	int i;
	//Contador para saber cuantos 1's tiene el numero 
	int contador = 0;
	//Ciclo para recorrer los bits
	for(i = 30 ; i>=0 ; i--)
		//Si el numero en la posicion i es 1 entonces el contador aumenta en 1
		if(n & (1<<i))
			contador++;
	//Verificamos si el numero de 1's es par regresamos 1
	if(contador % 2 == 0)
		return 1;
	//Si el numero de 1's es impar regresamos 0
	if(contador % 2 == 1)
		return 0;
}

/**
 *Funcion que encuentra el i-esimo numero de estocolmo
 *var: int v es la i-esima posicion
 *var: v lo multiplicamos por 2 y verificamos si ese numero es de estocolmo
 *     si no regresamos el numero siguiente, asegurando que uno de los dos
 *     es un numero de estocolmo
 *return n si el numero es de Estocolmo
 *return n+1 si el n no era un numero de Estocolmo
*/
int estocolmo(int v){
	int n = v*2;
	if(numeroEstocolmo(n) == 1)
		return n;
	else
		return n+1;

}

/**
 *Funcion que nos dice si un numero absurdamente grande es de Estocolmo
 *var: unsigned char * bits un arreglo de char's para poder crear nuestro numero
 *var nbytes el tamño del arreglo
 *return 1 si el numero es de Estocolmo
 *return 0 si el numero no es de Estocolmo
*/

int numeroEstocolmoCadena(unsigned char * bits, int nbytes){
	//Contador para llevar la cuenta de 1's 
	int contador = 0;
	//Iteradores para recorrer el arreglo y para recorrer los bits
	int i,j;
	//Ciclo para recorrer el arreglo 
	for (i=0; i < nbytes; ++i){
		//Creamos un unsigend char num que es un "string" para recorrer los bits del numero
		unsigned char num = bits[i];
		//Ciclo para recorrer los bits del numero 
		for (j=0; j < 8; j++){
			//Si el bit en la posicion i es 1 entonces aumentamos el contador en 1
			if(num & (1<<i))
				contador++;
		}
	}
	//Si el numero de bits es par entocnes es un numero de Estocolmo
	if(contador % 2 == 0)
		return 1;
	//Si el numero de bits es impar entonces no es un numero de Estocolmo
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
