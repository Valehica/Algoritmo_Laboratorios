#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
#define MAX 100

//struct Jugadores
typedef struct{
	char name[100];
	int nivel;
	int salud;
	int puntaje;	
}Jugador;

//Funcione de imprimir
void printArray(Jugador array[MAX], int cont){
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

int main(){
	int valor = 0;
	int opcion, opcion2;
	int cont1 = 0;
	int cont2 = 0;
	int k; 
	Jugador jugadores1[N];
	Jugador jugadores2[N];
	
	//Auxiliares
	int auxNivel;
	int auxSalud;
	int auxPuntaje;
	char auxName[MAX];
	
	while(valor == 0){
		//Se ingresa la opcion
		printf("\nIngrese una opcion \n\t>> 1 para ingresar un dato\n\t>> 2 para mostrar los datos\n\t>> 3 para salir\n");
		scanf("%d", &opcion);
		system("cls");
		
		if(opcion == 1){
			//Ingresar datos
			
			//Escoger que equipo ingresar datos
			printf("\nIngrese una opcion: \n\t>> 1 para añadir un jugador al equipo 1 \n\t>> 2 para añadar un jugador al equipo 2\n");
			scanf("%d", &opcion2);
			system("cls");
			
			if(opcion2 == 1){
				if(cont1 < 5){
					printf("|========| Jugador %d Equipo 1 |========|", cont1+1);
					
					//ingresar datos a auxiliares
					printf("\nIngrese el nombre del jugador: ");
					scanf("%s", &auxName);
					
					printf("Ingrese el nivel del jugador: ");
					scanf("%d", &auxNivel);
					
					printf("Ingrese el porcentaje de salud en numero entero (ej: 20 por ciento es 20): ");
					scanf("%d", &auxSalud);
					
					printf("Ingrese el puntaje del jugador:");
					scanf("%d", &auxPuntaje);
					
					system("cls");
					
					//Guardar datos
					for(k = 0; k < MAX; k++){
						jugadores1[cont1].name[k] = auxName[k];
						
					}
					jugadores1[cont1].nivel = auxNivel;
					jugadores1[cont1].puntaje = auxPuntaje;
					jugadores1[cont1].salud = auxSalud;
					cont1++;	
				}else{
					printf("\nHa exedido el limite de jugadores, ya no puede agregar otro jugador\n"); 
					system("pause");
					system("cls");
				}
				
				
			}else{
				
				if(cont2 < 5){
					printf("|========| Jugador %d Equipo 2 |========|", cont2+1);
					
					//ingresar datos a auxiliares
					printf("\nIngrese el nombre del jugador: ");
					scanf("%s", &auxName);
					
					printf("Ingrese el nivel del jugador: ");
					scanf("%d", &auxNivel);
					
					printf("Ingrese el porcentaje de salud en numero entero (ej: 20 por ciento es 20): ");
					scanf("%d", &auxSalud);
					
					printf("Ingrese el puntaje del jugador:");
					scanf("%d", &auxPuntaje);
					
					system("cls");	
					
					//Guardar datos
					for(k = 0; k < MAX; k++){
						jugadores2[cont2].name[k] = auxName[k];
						
					}
					jugadores2[cont2].nivel = auxNivel;
					jugadores2[cont2].puntaje = auxPuntaje;
					jugadores2[cont2].salud = auxSalud;
					cont2++;	
				}else{
					printf("\nHa exedido el limite de jugadores, ya no puede agregar otro jugador\n"); 
					system("pause");
					system("cls");
				}
				
			}
	
		}else if(opcion == 2){
			//leer datos
			
			//Escoger que equipo mostrar datos
			printf("\nIngrese una opcion: \n\t>> 1 para mostrar al equipo 1 \n\t>> 2 para mostrar al equipo 2\n");
			scanf("%d", &opcion2);
			system("cls");
			
			if(opcion2 == 1){
				printArray(jugadores1, cont1);
			}else{
				printArray(jugadores2, cont2);
			}
			
			
			system("pause");
			system("cls");
			
		}else{
			//salir 
			valor = 1;
			
		}
	}
	
}
