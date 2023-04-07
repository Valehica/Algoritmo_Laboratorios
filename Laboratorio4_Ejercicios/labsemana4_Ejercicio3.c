#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAXTEMPERATURE 30

//Definicion de la estructura
typedef struct {
char name[50];
int age;
int room;
float temperature[MAX];
} Patient;

int main(){
	//Variabes utilidd struct 
	Patient patients[MAX];
	Patient *point;
	point = (Patient *)malloc(MAX *sizeof(Patient)); //Se leasgina el espacio de memoria con malloc
	
	//Variables menu
	int opcion;
	int i, k;
	int valor = 0;
	int cant = 0;
	int numPatients;
	
	//Inicializacion temperature patients
	for(i = 0; i < MAX; i++){
		for(k = 0; k < MAXTEMPERATURE; k++){
			patients[i].temperature[k] = 0;
		}
	}
	
	
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
		printf("Ingrese una opcion \n\t>> 1 para agregar un paciente \n\t>> 2 para agregar una temperatura a un paciente \n\t>> 3 para imprimir la lista de pacientes \n\t>> 4 para salir\n");
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
			//Agregar temperatura a un paciente 
			recordTemperature(&point, cant);
			
		}else if(opcion == 3){
			//Se imprime a lista
			printPatients(&point, cant);
			system("pause");
			system("cls");
		}else{
			//Salir
			valor = 1;
		}
	}
	
	free(point);
	return 0;
}

//Funcion para agregar una temperature
recordTemperature(Patient* point, int cant){
	int i;
	int numberPat;
	int indiceCero;
	float temperatureAux;
	
	printPatients(&point, cant);
	
	printf("\nIngrese el numero del paciente al que quiere registrar nueva temperatura: ");
	scanf("%d", &numberPat);
	
	for(i = 0; i < MAXTEMPERATURE; i++){
		if(point[numberPat - 1].temperature[i] == 0){
			i = indiceCero; //Esto es para registrar desde donde hay que ingresar nuevas temperaturas
		}
	}
	printf("Ingreso de temperatura de paciente %d (si ya no desea ingresar mas dias ingrese el valor 0): \n", numberPat);
	for(i = indiceCero; i < MAXTEMPERATURE; i++){
		printf("\t>> temperatura dia %d: ", i + 1); 
		scanf("%f", &temperatureAux);
		
		if(temperatureAux == 0){
			break;
		}else{
			point[numberPat - 1].temperature[i] = temperatureAux;
		}
	}
	
}

//Funcion para imprimir los pacientes
printPatients(Patient* point, int cant){
	int i;
	int k; 
	
	printf("|====| INFORMACION PACIENTES |====|\n");
	for(i = 0; i < cant; i++){
		printf("\nPaciente [%d] \n", i+1);
		printf("   El nombre del paciente %d es: %s \n", i+1, point[i].name);
		printf("   La edad del paciente %d es: %d \n", i+1, point[i].age);
		printf("   La habitacion del paciente %d es: %d \n", i+1, point[i].room);
		printf("   La temperatura del paciente %d es: \n", i+1);
		for(k = 0; k < MAXTEMPERATURE; k++){
			if(point[i].temperature[k] != 0){
				printf("\t   >> Temperatura dia %d: %.2f\n", k + 1, point[i].temperature[k]);
			}
		}
	}

}


//Funcion para agregar los pacentes
addPatient(Patient* point, int number){
	int i;
	float temperatureAux;
	
	printf("Ingrese el nombre del paciente %d: ", number + 1);
	scanf("%s", &point[number].name);//Se guarda en la unidad de memoria point

	printf("Ingrese la edad del paciente %d: ", number + 1);
	scanf("%d", &point[number].age);
	
	printf("Ingrese la habitacion del paciente %d: ", number + 1);
	scanf("%d", &point[number].room);
	
	printf("Ingreso de temperatura de paciente %d (si ya no desea ingresar mas dias ingrese el valor 0): \n", number + 1);
	for(i = 0; i < MAXTEMPERATURE; i++){
		printf("\t>> temperatura dia %d: ", i + 1); 
		scanf("%f", &temperatureAux);
		
		if(temperatureAux == 0){
			break;
		}else{
			point[number].temperature[i] = temperatureAux;
		}
	}
	
	
	printf("\n");
	
	system("cls");
}
