#include <stdio.h>

#define N 100
#define M 100

int main(){
	int pacientes[N][M];
	int i, k, opcion, opPaciente, suma,indice ;
	int valorMenu = 0;
	int cont = 0;
	
	for(i = 0; i < N; i++){
		for(k = 0; k < M; k++){
			pacientes[i][k] = 0;
		}
	}
	
	printf("Ingrese el numero de habitacion del paciente: ");
	scanf("%d", &pacientes[cont][0]);
	
	printf("Ingrese la edad del paciente: ");
	scanf("%d", &pacientes[cont][1]);
	
	for(i = 0; i < M; i++){
		printf("Ingrese la temperatura del dia %d del paciente (Ingrese 0 para salir): ", i+1);
		scanf("%d", &pacientes[cont][i+2]);
		
		if(pacientes[cont][i+2] == 0){
			if(i > 7){
				i = 100;	
			}else{
				printf("\nDebe ingresar por lo menos 7 dias de temperatura...\n\n");
			}	
		}
	}
	cont++;
		
	while(valorMenu == 0){
		printf("\ningrese una opcion \n\t>> 1 para añadir un paciente \n\t>> 2 para buscar un paciente \n\t>> 3 para mostrar todos los pacientes\n");
		scanf("%d", &opcion);
		
		if(opcion == 1){
			printf("Ingrese el numero de habitacion del paciente: ");
			scanf("%d", &pacientes[cont][0]);
			
			printf("Ingrese la edad del paciente: ");
			scanf("%d", &pacientes[cont][1]);
			
			for(i = 0; i < M; i++){
				printf("Ingrese la temperatura del dia %d del paciente (Ingrese 0 para salir): ", i+1);
				scanf("%d", &pacientes[cont][i+2]);
				
				if(pacientes[cont][i+2] == 0){
					if(i > 7){
						i = 100;	
					}else{
						printf("\nDebe ingresar por lo menos 7 dias de temperatura...\n\n");
					}	
				}
			}
			
			cont++;
			
		}else if(opcion == 2){
			printf("Ingrese la habitacion del paciente: ");
			scanf("%d", &opPaciente);
			
			for(i = 0; i < N; i++){
				suma = 0;
				indice = 0;
				
				if(opPaciente == pacientes[i][0]){
					printf("Numero de habitacion: %d\n", pacientes[i][0]);
					printf("Edad del paciente: %d\n", pacientes[i][1]);
					
					for(k = 2; k < N; k++){
						if(pacientes[i][k] != 0){
							suma = suma + pacientes[i][k];
							indice++;
						}
					}
					printf("Temperatura promedio: %f\n", (float)suma/(indice));
				}
			}
		}else{
			
			for(i = 0; i < N; i++){
				suma = 0;
				indice = 0;
				if(pacientes[i][0] != 0){
					printf("|===| PACIENTE N°%d |====|\n", i+1);
					printf("\tNumero de habitacion: %d\n", pacientes[i][0]);
					printf("\tEdad del paciente: %d\n", pacientes[i][1]);
					
					for(k = 2; k < N; k++){
						if(pacientes[i][k] != 0){
							suma = suma + pacientes[i][k];
							indice++;
						}
					}
					printf("\tTemperatura promedio: %f\n\n", (float)suma/(indice));	
				}
				
				
			}
		}
	}
	 
}
