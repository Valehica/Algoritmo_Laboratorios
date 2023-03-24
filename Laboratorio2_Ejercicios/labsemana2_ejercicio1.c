#include <stdio.h>
#define N 100
#define M 2


int main(){
	int elementos[N][M];
	int i, k, id,cant;
	int cont = 0;
	int valor = 0;
	int valorMenu = 0;  
	
	//Inicializacion
	for(i = 0; i < N; i++){
		for(k = 0; k < M; k++){
			elementos[i][k] = 0; 
		}
	}
	
	while(valorMenu == 0){
					
		//Ingresar un elemento recolectado; 
		printf("Ingrese la identificacion del elemento recolectado: "); 
		scanf("%d", &id);
		
		for(i = 0; i < N; i++){
			if(id == elementos[i][0]){
				printf("Ingrese la cantidad de elementos recolectados con este id: ");
				scanf("%d", &cant);
				
				elementos[i][0] = id;
				elementos[i][1] = elementos[i][1] + cant;
				valor = 1; 
				
				system("cls");
			}
		}
		if(valor == 0){
			printf("Ingrese la cantidad de elementos recolectados con este id: ");
			scanf("%d", &cant);
			elementos[cont][0] = id;
			elementos[cont][1] = elementos[cont][1] + cant;
			cont++;
			
			system("cls");
		}
	
		//Mostrar los elementos 
		
		if(cont == 0){
			printf("No hay elementos ingresados... \n\n");
		}else{
			printf("Los elementos recolectados son: \n\n");
			for(i = 0; i < cont; i++){
				printf("- Elemento #%d: %d\n", elementos[i][0], elementos[i][1]);
			}
		}
		
		printf("\n");
		system("pause");
		system("cls");
		
		
		valor = 0; 
	}
	return 0;
}
