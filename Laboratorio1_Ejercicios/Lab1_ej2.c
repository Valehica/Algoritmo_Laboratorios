//Ejercicio 2 Laboratorio 1 Algoritmos
//Operaciones Basicas

#include <stdio.h>

int main(){
	int numero; 
	printf("Ingrese un numero : ");
	scanf("%d", &numero);
	
	
	printf("\nSi a su numero le sumamos 10 se tiene como resultado: %d\n\n", numero + 10);
	printf("Si a su numero le sumamos 5 se tiene como resultado: %d\n\n", numero - 5);
	printf("Si a su numero lo multiplicamos por 6 se tiene como resultado: %d\n\n", numero * 6);
	printf("Si a su numero lo dividimos por 2 se tiene como resultado: %f \n\n", ((float)numero/2));
	
	
	return 0; 
}
