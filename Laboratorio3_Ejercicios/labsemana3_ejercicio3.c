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
	int opcion, opcion2, opcion3;
	int cont1 = 0;
	int cont2 = 0;
	int valorMod = 0;
	int k, i; 
	int indiceMod;
	int sumaPuntajeA = 0;
	int sumaPuntajeB = 0;
	Jugador jugadores1[N];
	Jugador jugadores2[N];
	
	//Auxiliares
	int auxNivel;
	int auxSalud;
	int auxPuntaje;
	char auxName[MAX];
	
	while(valor == 0){
		//Se ingresa la opcion
		printf("\nIngrese una opcion \n\t>> 1 para ingresar un dato\n\t>> 2 para mostrar los datos\n\t>> 3 para modificar un jugador\n\t>> 4 para determianr que equipo gano \n\t>> 5 para salir\n");
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
			
		}else if (opcion == 3){
			printf("\nIngrese una opcion: \n\t>> 1 para modificar un jugador del equipo 1 \n\t>> 2 para modificar un jugador del equipo 2\n");
			scanf("%d", &opcion2);
			system("cls");
			
			if(opcion2 == 1){
				//Modificar equipo 1
				printf("|========| LISTA EQUIPO 1 |=======|\n");
				printArray(jugadores1, cont1);
				
				//Pedir el jugador
				printf("\nIngrese el numero del jugador que desea modificar: ");
				scanf("%d", &indiceMod - 1);
				system("cls");
				
				while(valorMod == 0){
					printf("\nIngrese una opcion: \n\t>> 1 para modificar el nombre \n\t>> 2 para modificar el nivel \n\t>> 3 para modificar el porcentaje de salud \n\t>> 4 para modificar el puntaje \n\t>> 5 para salir\n");
					scanf("%d", &opcion3);
					system("cls");
					
					if(opcion3 == 1){
						//modificar el nombre
						printf("\nIngrese el nuevo nombre del jugador: ");
						scanf("%s", &auxName);
						
						for(k = 0; k < MAX; k++){
							jugadores1[indiceMod].name[k] = auxName[k];
							
						}	
						system("cls");
						
					}else if(opcion3 == 2){
						//modificar el nivel
						printf("Ingrese el nuevo nivel del jugador: ");
						scanf("%d", &auxNivel);
						jugadores1[indiceMod].nivel = auxNivel;
						system("cls");
						
					}else if(opcion3 == 3){
						//modificar el porcentaje de salud
						printf("Ingrese el porcentaje de salud en numero entero (ej: 20 por ciento es 20): ");
						scanf("%d", &auxSalud);
						jugadores1[indiceMod].salud = auxSalud;
						system("cls");
					
					}else if(opcion3 == 4){
						//modificar el puntaje
						printf("Ingrese el puntaje del jugador:");
						scanf("%d", &auxPuntaje);
						jugadores1[indiceMod].puntaje = auxPuntaje;
						system("cls");
						
					}else{
						valorMod = 1;
					}
				}
				
			}else{
				//Modificar equipo 2
				printf("|========| LISTA EQUIPO 2 |=======|\n");
				printArray(jugadores2, cont2);
				
				//Pedir el jugador
				printf("\nIngrese el numero del jugador que desea modificar: ");
				scanf("%d", &indiceMod - 1);
				system("cls");
				
				while(valorMod == 0){
					printf("\nIngrese una opcion: \n\t>> 1 para modificar el nombre \n\t>> 2 para modificar el nivel \n\t>> 3 para modificar el porcentaje de salud \n\t>> 4 para modificar el puntaje \n\t>> 5 para salir\n");
					scanf("%d", &opcion3);
					system("cls");
					
					if(opcion3 == 1){
						//modificar el nombre
						printf("\nIngrese el nuevo nombre del jugador: ");
						scanf("%s", &auxName);
						
						for(k = 0; k < MAX; k++){
							jugadores2[indiceMod].name[k] = auxName[k];
							
						}	
						system("cls");
						
					}else if(opcion3 == 2){
						//modificar el nivel
						printf("Ingrese el nuevo nivel del jugador: ");
						scanf("%d", &auxNivel);
						jugadores2[indiceMod].nivel = auxNivel;
						system("cls");
						
					}else if(opcion3 == 3){
						//modificar el porcentaje de salud
						printf("Ingrese el porcentaje de salud en numero entero (ej: 20 por ciento es 20): ");
						scanf("%d", &auxSalud);
						jugadores2[indiceMod].salud = auxSalud;
						system("cls");
					
					}else if(opcion3 == 4){
						//modificar el puntaje
						printf("Ingrese el puntaje del jugador:");
						scanf("%d", &auxPuntaje);
						jugadores2[indiceMod].puntaje = auxPuntaje;
						system("cls");
						
					}else{
						valorMod = 1;
					}
				}
			}
			
		}else if (opcion == 4){
			//verificar que equipo gano
			for(i= 0; i < N; i++){
				sumaPuntajeA = sumaPuntajeA + jugadores1[i].puntaje;
				sumaPuntajeB = sumaPuntajeA + jugadores2[i].puntaje;	
			}
			if(sumaPuntajeA == sumaPuntajeB){
					printf("|========| RESULTADO |========|");
					printf("\n\nAmbos equipos han empatado ...\n\n");
					system("pause");
					system("cls");
				}else if(sumaPuntajeA > sumaPuntajeB){
					printf("|========| RESULTADO |========|");
					printf("\n\nEl equipo 1 ha ganado ...\n\n");
					system("pause");
					system("cls");
				}else{
					printf("|========| RESULTADO |========|");
					printf("\n\nEl equipo 2 ha ganado ...\n\n");
					system("pause");
					system("cls");
				}
			
		}else{
			//salir 
			valor = 1;
			
		}
	}
	
}
