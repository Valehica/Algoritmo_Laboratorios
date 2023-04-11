#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//Definicion de la estructura
typedef struct {
char name[50];
int age;
int room;
float temperature;
} Patient;

int main(){
	//Variabes utilidd struct 
	Patient patients[MAX];
	Patient *point;
	point = (Patient *)malloc(MAX *sizeof(Patient)); //Se leasgina el espacio de memoria con malloc
	
	//Variables menu
	int opcion;
	int valor = 0;
	int cant = 0;
	int numPatients;
	
	//[INICIO DEL PROGRAMA]
	
	//Pedir la cantidad de pacientes
	while(valor == 0){
		printf("Ingrese la cantiadad de pacientes que deseaa ingresar como maximo: ");
		scanf("%d", &numPatients);
		system("cls");
		
		if(numPatients > MAX){
			printf("El valor ingresado es muy grande, intentelo de nuevo\n\n");
			system("pause");
			system("cls");
		}else{
			valor = 1;
		}
	}
	
	
	//Opciones
	valor = 0;
	while(valor == 0){
		printf("Ingrese una opcion \n\t>> 1 para agregar un paciente \n\t>> 2 para imprimir la lista de pacientes \n\t>> 3 para salir\n");
		scanf("%d", &opcion);
		system("cls");
		
		if(opcion == 1){
			//Se ingresa un paciente 
			if(cant < numPatients){
				addPatient(&point, cant);
				cant++;
			}else{
				printf("Ya no se pueden ingresar mas pacientes, la capacidad esta llena\n\n");
				system("pause");
				system("cls");
			}
			
		}else if(opcion == 2){
			//Se imprime a lista
			printPatients(&point, cant);
		}else{
			//Salir
			valor = 1;
		}
	}
	
	free(point);
	return 0;
}

//Funcion para imprimir los pacientes
printPatients(Patient* point, int cant){
	int i;
	printf("|====| INFORMACION PACIENTES |====|\n\n");
	for(i = 0; i < cant; i++){
		printf("El nombre del paciente %d es: %s \n", i+1, point[i].name);
		printf("La edad del paciente %d es: %d \n", i+1, point[i].age);
		printf("La habitacion del paciente %d es: %d \n", i+1, point[i].room);
		printf("La temperatura del paciente %d es: %.2f \n\n", i+1, point[i].temperature);
	}
	
	system("pause");
	system("cls");
}


//Funcion para agregar los pacentes
addPatient(Patient* point, int number){
	printf("Ingrese el nombre del paciente %d: ", number + 1);
	scanf("%s", &point[number].name);//Se guarda en la unidad de memoria point

	printf("Ingrese la edad del paciente %d: ", number + 1);
	scanf("%d", &point[number].age);
	
	printf("Ingrese la habitacion del paciente %d: ", number + 1);
	scanf("%d", &point[number].room);
	
	printf("Ingrese la temperatura del paciente %d: ", number + 1);
	scanf("%f", &point[number].temperature);
	
	printf("\n");
	
	system("cls");
}
