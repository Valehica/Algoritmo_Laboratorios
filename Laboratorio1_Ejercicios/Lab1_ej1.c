//Ejercicio 1 Laboratorio 1 Algoritmos
//Ocupar variables basicas

#include <stdio.h>

int main() {
	int entero = 5;
	float decimalFloat = 1.4;
	double decimalDouble = 1.4444444444444444444;
	char letras[4] = "hola";

	printf("La variable int es un numero entero, por ejemplo: %d\n\n", entero);
	printf("La variable float es un decimal que guarda menor informacion que la variable double, por ejemplo: %f\n\n", decimalFloat);
	printf("La variable double es un numero decimal que guarda mas informacion que la variable float, por ejemplo: %f\n\n", decimalDouble);
	printf("La variable char son caracteres, por ejemplo la palabra: %s \n\n", letras);

	return 0;
}
