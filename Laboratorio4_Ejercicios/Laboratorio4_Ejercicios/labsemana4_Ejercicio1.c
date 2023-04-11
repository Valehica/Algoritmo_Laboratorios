#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

//Definicion de la estructura
typedef struct {
char name[50];
int age;
int room;
float temperature;
} Patient;

int main(){
	Patient patients[MAX];
	Patient *point;
	point = (Patient *)malloc(MAX *sizeof(Patient)); //Se leasgina el espacio de memoria con malloc
	
	int i;
	
	//Ingresar los pacientes
	for(i = 0; i < MAX; i++){
		addPatient(&point, i);
	}
	
	//Imprimir pacientes
	printPatients(&point);
	
	free(point);
	return 0;
}

//Funcion para imprimir los pacientes
printPatients(Patient* point){
	int i;
	printf("|====| INFORMACION PACIENTES |====|\n\n");
	for(i = 0; i < MAX; i++){
		printf("El nombre del paciente %d es: %s \n", i+1, point[i].name);
		printf("La edad del paciente %d es: %d \n", i+1, point[i].age);
		printf("La habitacion del paciente %d es: %d \n", i+1, point[i].room);
		printf("La temperatura del paciente %d es: %.2f \n\n", i+1, point[i].temperature);
	}
	
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
}
