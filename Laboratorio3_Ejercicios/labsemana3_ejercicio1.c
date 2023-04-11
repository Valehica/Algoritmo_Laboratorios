#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

//struct Jugadores
typedef struct{
	char name[100];
	int nivel;
	int salud;
	int puntaje;	
}Jugador;

//Funcione de imprimir
void printArray(Jugador* array, int cont){
	int i;
	int k;
	
	for(i= 0; i < cont; i++){
		printf("|========| Jugador %d |========|\n\n", i+1);
		printf("  >> Nombre: ");
		int len = strlen(array[i].name);
		for(k= 0; k < len; k++){
			
			printf("%c", array[i].name[k]);
		}
		printf("\n  >> Nivel: %d\n", array[i].nivel);
		printf("  >> Porcentaje de salud: %d\n", array[i].salud);
		printf("  >> Puntaje: %d\n\n", array[i].puntaje);
		
	}
}
addjugador(Jugador* point, int *cont){
	
	printf("|========| Jugador %d |========|\n", *cont+1);
	printf("\nIngrese el nombre del jugador: ");
	scanf("%s", &point[*cont].name);
	
	printf("Ingrese el nivel del jugador: ");
	scanf("%d", &point[*cont].nivel);
	
	printf("Ingrese el porcentaje de salud en numero entero (ej: 20 por ciento es 20): ");
	scanf("%d", &point[*cont].salud);
	
	printf("Ingrese el puntaje del jugador:");
	scanf("%d", &point[*cont].puntaje);
	
	system("cls");
		

	
	*cont = *cont + 1;
}

int main(){
	int valor = 0;
	int opcion;
	int cont = 0;
	int k; 
	Jugador jugadores[N];
	Jugador *point = (Jugador *)malloc(N *sizeof(Jugador));
	
	//Auxiliares
	int auxNivel;
	int auxSalud;
	int auxPuntaje;
	char auxName[N];
	
	while(valor == 0){
		//Se ingresa la opcion
		printf("\nIngrese una opcion \n\t>> 1 para ingresar un dato\n\t>> 2 para mostrar los datos\n\t>> 3 para salir\n");
		scanf("%d", &opcion);
		system("cls");
		
		if(opcion == 1){
			//Ingresar datos
			addjugador(&point, &cont);
			
		}else if(opcion == 2){
			
			//leer datos
			if(cont < 2){
				printf("\nUsted debe agregar como minimo 3 jugadores\n\n");
				system("pause");
				system("cls");
			}else{
				printArray(jugadores, cont);
			
				system("pause");
				system("cls");
			}
			
			
		}else{
			//salir 
			valor = 1;
		}
	}
	
}
