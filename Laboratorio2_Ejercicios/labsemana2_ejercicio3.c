#include <stdio.h>
#define N 100
#define M 2


int main(){
	int elementos[N][M];
	int i, k, id, cant, opcion;
	int cont = 6;
	int valor = 0;
	int valorMenu = 0;  
	
	//Inicializacion de los inventarios
	for(i = 0; i < N; i++){
		for(k = 0; k < M; k++){
			elementos[i][k] = 0;
		}
	}
	
	//LLenado random de los inventarios para evitar llenarlos 
	for(i = 0; i < 6; i++){
		elementos[i][0] = rand() % 11;
		elementos[i][1] = rand() % 60;
	} 
	
	
	while(valorMenu == 0){
		
		//Mostrar los elementos 
		if(cont == 0){
			printf("No hay elementos ingresados... \n\n");
		}else{
			printf("|====| INVENTARIO (id:cant) |====|\n");
			for(i = 0; i < N; i++){
				if(elementos[i][0] != 0){
					printf("#%d : %d\n", elementos[i][0], elementos[i][1]);	
				}
			}
		}
		
		printf("\nIngrese una opcion: \n\t>> 1 para Agregar \n\t>> 2 para Eliminar\n");
		scanf("%d", &opcion); 
		
		if(opcion == 1){
			//Opcion Agregar
			valor = 0;
			printf("Ingrese la identificacion del elemento que desee agregar: "); 
			scanf("%d", &id);
			
			for(i = 0; i < N; i++){
				if(elementos[i][0] == id){
					printf("\nSe ha agregado un elemento al elemento #%d\n", id);
					elementos[i][1]++;
					valor = 1;
				}	
			}
			if(valor == 0){
				printf("\nSe ha agregado un elemento al elemento #%d\n", id);
				elementos[cont][0] = id;
				elementos[cont][1] = 1;
				cont++;
			}
			
		}else{
			//Opcion Eliminar
			printf("Ingrese la identificacion del elemento que desee eliminar: "); 
			scanf("%d", &id);
			
			for(i = 0; i < N; i++){
				if(elementos[i][0] == id){
					if(elementos[i][1] == 1){
						printf("\nSe ha eliminado el elemento #%d\n", id);
						elementos[i][0] = 0;
						elementos[i][1] = 0;
					}else{
						elementos[i][1]--;
						printf("\nSe ha eliminado un elemento al elemento #%d\n", id);
					}
				}	
			}
			
			
		}
					
		
		printf("\n");
		system("pause");
		system("cls");
		
		
		valor = 0; 
	}
	return 0;
}
