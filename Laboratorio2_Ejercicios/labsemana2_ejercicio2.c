#include <stdio.h>
#include <time.h>

#define N 100
#define M 2


int main(){
	int elementosA[N][M];
	int elementosB[N][M];
	int elementosC[N][M];
	int i, k, opcion = 0, valor,id, cant;
	int valorMenu = 0;
	int contA = 6; 
	int contB = 6;
	int cont = 6;
	
	//Inicializacion de los inventarios
	for(i = 0; i < N; i++){
		for(k = 0; k < M; k++){
			elementosA[i][k] = 0;
			elementosB[i][k] = 0;
			elementosC[i][k] = 0;
		}
	}
	
	//LLenado random de los inventarios para evitar llenarlos 
	for(i = 0; i < 6; i++){
		elementosA[i][0] = rand() % 11;
		elementosA[i][1] = rand() % 60;
	} 
	for(i = 0; i < 6; i++){
		elementosB[i][0] = rand() % 11;
		elementosB[i][1] = rand() % 60;
	} 
	
	
	
	
	while(valorMenu == 0){
		if(opcion != 3){
			printf("|====| INVENTARIO A (id:cant) |====|\n");
			for(i = 0; i < N; i++){
				if(elementosA[i][0] != 0){
					printf("#%d : %d\n", elementosA[i][0], elementosA[i][1]);	
				}
			} 
			
			printf("\n\n|====| INVENTARIO B (id:cant) |====|\n");
			for(i = 0; i < N; i++){
				if(elementosB[i][0] != 0){
					printf("#%d : %d\n", elementosB[i][0], elementosB[i][1]);
				}
			} 	
		}
		
		printf("\nIngrese una opcion: \n\t>> 1 para añadir elementos al inventario A \n\t>> 2 para añadir elementos al inveentario B \n\t>> 3 para fusionar los inventarios\n");
		scanf("%d", &opcion);
		
		if(opcion == 1){
			//Añadir elementos al inventario A
			printf("Ingrese la identificacion del elemento recolectado: "); 
			scanf("%d", &id);
			
			for(i = 0; i < N; i++){
				if(id == elementosA[i][0]){
					printf("Ingrese la cantidad de elementos recolectados con este id: ");
					scanf("%d", &cant);
					
					elementosA[i][0] = id;
					elementosA[i][1] = elementosA[i][1] + cant;
					valor = 1; 
					
					system("cls");
				}
			}
			if(valor == 0){
				printf("Ingrese la cantidad de elementos recolectados con este id: ");
				scanf("%d", &cant);
				elementosA[contA][0] = id;
				elementosA[contA][1] = elementosA[contA][1] + cant;
				contA++;
				
				system("cls");
			}
			
		}else if(opcion == 2){
			//Añadir elementos al inventario B
			printf("Ingrese la identificacion del elemento recolectado: "); 
			scanf("%d", &id);
			
			for(i = 0; i < N; i++){
				if(id == elementosB[i][0]){
					printf("Ingrese la cantidad de elementos recolectados con este id: ");
					scanf("%d", &cant);
					
					elementosB[i][0] = id;
					elementosB[i][1] = elementosB[i][1] + cant;
					valor = 1; 
					
					system("cls");
				}
			}
			if(valor == 0){
				printf("Ingrese la cantidad de elementos recolectados con este id: ");
				scanf("%d", &cant);
				elementosB[contB][0] = id;
				elementosB[contB][1] = elementosB[contB][1] + cant;
				contB++;
				
				system("cls");
			}
			
		}else{
			//Fusionar los invenrios [NUVA FUNCION]
			for(i = 0; i < N; i ++){
				elementosC[i][0] = elementosA[i][0];
				elementosC[i][1] = elementosA[i][1];
			}
			
	
					
			for(i = 0; i < contB; i ++){
				valor = 0;
				for(k = 0; k < cont; k++){
					if(elementosC[k][0] == elementosB[i][0]){
						elementosC[k][1] = elementosC[k][1] + elementosB[i][1];
						valor = 1;
					}
				}
				if(valor == 0){
					elementosC[cont][0] = elementosB[i][0];
					elementosC[cont][1] = elementosB[i][1];
					cont++;
				}
			}
			
			printf("\n\n|====| INVENTARIO FUSIONADO (id:cant) |====|\n");
			for(i = 0; i < N; i++){
				if(elementosC[i][0] != 0){
					printf("#%d : %d\n", elementosC[i][0], elementosC[i][1]);
				}
			} 
			
		}
	}
	return 0;
}
