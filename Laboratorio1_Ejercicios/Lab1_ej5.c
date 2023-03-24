//Ejercicio 5 Laboratorio 1 Algoritmos

#include <stdio.h>
#include <time.h>

int main(){
	//crear numeros aleatorios
	int aleatInicio = rand() % 7;
	int aleatNext = rand() % 7;
	int valor = 1;
	
	while(valor == 1){
		printf("\nLa pieza que salio tiene id #%d\n", aleatInicio);
		
		//comprobar si se repite 
		while(aleatNext == aleatInicio){
			aleatNext = rand() % 7;
		}
		printf("La pieza siguiente tiene id #%d\n\n", aleatNext);
		aleatInicio = rand() % 7;
		aleatNext = rand() % 7;
		
		//comprobar si se repite 
		while(aleatNext == aleatInicio){
			aleatInicio = rand() % 7;
		}
		
		system("pause");
	}	
	
	
	return 0; 
}
