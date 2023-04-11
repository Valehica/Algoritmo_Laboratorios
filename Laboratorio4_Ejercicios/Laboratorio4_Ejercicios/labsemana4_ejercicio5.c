#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAXTEMP 30

//Definicion de la estructura
typedef struct Patient {
	char name[50];
	int age;
	int room;
	float temperature[MAXTEMP];
	struct Patient *sig;

} Patient;

//agregar un paciente
addPatient(Patient** cabeza, int* number){
	char newName[50];
	int newAge, newRoom, i;
	float newTemp[MAXTEMP], auxTemp;
	
	//Inicializacion e array temp
	for(i = 0; i < MAXTEMP; i++){
		newTemp[i] = 0;
	}
	//Pedir los datos y guardarlos en variables auxiiares
	printf("Ingrese el nombre del paciente %d: ", *number + 1);
	scanf("%s", &newName);
	printf("Ingrese la edad del paciente %d: ", *number + 1);
	scanf("%d", &newAge);
	printf("Ingrese la habitacion del paciente %d: ", *number + 1);
	scanf("%d", &newRoom);
	printf("Ingreso de temperatura de paciente %d (si ya no desea ingresar mas dias ingrese el valor 0): \n", *number + 1);
	for(i = 0; i < MAXTEMP; i++){
		printf("\t>> temperatura dia %d: ", i + 1); 
		scanf("%f", &auxTemp);
		
		if(auxTemp == 0){
			break;
		}else{
			newTemp[i] = auxTemp;
		}
	}
	
	//Creacion del nodo y llenado del nodo
	Patient* newNodo = (Patient*)malloc(sizeof(Patient));
	newNodo->age = newAge;
	newNodo->sig = NULL;
	
	for(i = 0; i < 50; i++){
		newNodo->name[i] = newName[i];
	}
	newNodo->room = newRoom;
	for(i = 0; i < MAXTEMP; i++){
		newNodo->temperature[i] = newTemp[i];
	}
	
	//veridicar si existe un elemento en la lista
	if(*cabeza == NULL){
		*cabeza = newNodo;//Si no existe asignarle el nodo creado
	}else{
		Patient* nodoActual = *cabeza;
		Patient* nodoAux = newNodo;
		nodoAux->sig = nodoActual;
		*cabeza = newNodo;
		
		
	}
	*number = *number + 1;
	system("cls");
}

//Imprimir la lista
printPatients(Patient *cabeza){
	//crear un nuevo patient para recorrer el original
	Patient* nodoActual = cabeza;
	int i, k, cont = 1;
	
	printf("|====| INFORMACION PACIENTES |====|\n");
	
	while(nodoActual != NULL){
		//Imprimir cada elemento 
		printf("\nPaciente %d: \n", cont);
		printf("   El nombre del paciente %d es: %s \n", cont, nodoActual->name);
		printf("   La edad del paciente %d es: %d \n", cont, nodoActual->age);
		printf("   La habitacion del paciente %d es: %d \n", cont, nodoActual->room);
		printf("   La temperatura del paciente %d es: \n", cont);
		for(k = 0; k < MAXTEMP; k++){
			if(nodoActual->temperature[k] != 0){
				printf("\t   >> Temperatura dia %d: %.2f\n", k + 1, nodoActual->temperature[k]);
			}
		}
		cont++;
		nodoActual = nodoActual->sig;//Ahora se avanzo en el siguiente elemento de la lista
	}
	
}

//para conocer los datos del siguiente pacientes
getNextPatient(Patient** cabeza){
	//crear un nuevo patient para recorrer el original
	Patient* nodoActual = *cabeza;
	Patient* cabezaAux = nodoActual->sig;
	
	int i, k, opcion;
	
	//Imprimir cada elemento 
	printf("   El nombre del paciente es: %s \n", nodoActual->name);
	printf("   La edad del paciente es: %d \n",  nodoActual->age);
	printf("   La habitacion del paciente es: %d \n",  nodoActual->room);
	printf("   La temperatura del paciente es: \n");
	for(k = 0; k < MAXTEMP; k++){
		if(nodoActual->temperature[k] != 0){
			printf("\t   >> Temperatura dia %d: %.2f\n", k + 1, nodoActual->temperature[k]);
		}
	}

	nodoActual = nodoActual->sig;//Ahora se avanzo en el siguiente elemento de la lista
	
	printf("\nIngrese una opcion \n\t>> 1 para conocer los datos del siguiente paciente \n\t>> otro valor para salir de este menu \n");
	scanf("%d", &opcion);
	if(opcion == 1){
		if(nodoActual != NULL){
			getNextPatient(&cabezaAux);
		}else{
			printf("Ya no hay mas pacientes en cola\n");
		}
		
	}
	
}

//Dar de alta a un paciente
Patient* dischargePatient(Patient** cabeza){
	Patient* nodo_eliminar = *cabeza;
	if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
    }else{
    	printf("Se ha dado de alta al paciente %s\n", nodo_eliminar->name);
		system("pause");
		system("cls");
		*cabeza = nodo_eliminar->sig;
		free(nodo_eliminar); 	
	}	
	return *cabeza;	
}
freePatients(Patient *cabeza){
	free(cabeza);
}

getQueueSize(Patient** cabeza){
	Patient* nodoActual = *cabeza;
	int cont = 0;
	
	while(nodoActual != NULL){
		cont++;
		nodoActual = nodoActual->sig;
	}
	
	printf("Quedan %d en cola por atentender\n\n", cont);
	system("pause");
	system("cls");
}

getLeftPatients(Patient** cabeza){
	Patient* nodoActual = *cabeza;
	
	int busHab, cont = 0, valor = 0;
	
	printf("Ingrese la habitacion del paciente que desea conocer: ");
	scanf("%d", &busHab);
	
	while(nodoActual != NULL){
		if(nodoActual->room == busHab){
			valor = 1;	
			break;
		}else{
			nodoActual = nodoActual->sig;
		}
		cont++;
	}
	if(valor == 0){
		printf("No se ha encontrado el paciente\n\n");
		system("pause");
		system("cls");
	}else{
		printf("Quedan %d en cola por atentender\n\n", cont);
		system("pause");
		system("cls");
	}
	
}

int main(){
	//Variabes utilidd struct 
	Patient* cabeza = NULL;
	
	//Variables menu
	int opcion;
	int i, k;
	int valor = 0;
	int cont = 0;
	
	
	//[INICIO DEL PROGRAMA]
	//Opciones
	valor = 0;
	while(valor == 0){
		printf("Ingrese una opcion \n\t>> 1 para agregar un paciente \n\t>> 2 para imprimir la lista de pacientes \n\t>> 3 para dar de alta a un paciente \n\t");
		printf(">> 4 para conocer los datos del siguiente pacientes \n\t>> 5 para conocer cuántos pacientes faltan por atender \n\t>> 6 para conocer cuántos pacientes faltan para el turno de un paciente \n\t>> 7 para salir\n");
		scanf("%d", &opcion);
		system("cls");
		
		if(opcion == 1){
			//Se ingresa un paciente 
			addPatient(&cabeza, &cont);
			
			
		}else if(opcion == 2){
			//Se imprime a lista
			printPatients(cabeza);
			system("pause");
			system("cls");
		}else if(opcion == 3){
			//quitar de la cola
			cabeza = dischargePatient(&cabeza);
		}else if(opcion == 4){
			//para conocer los datos del siguiente pacientes
			getNextPatient(&cabeza);
			system("cls");
		}else if(opcion == 5){
			//para conocer cuántos pacientes faltan por atender
			getQueueSize(&cabeza);
			
		}else if(opcion == 6){
			//para conocer cuántos pacientes faltan para el turno de un paciente
			getLeftPatients(&cabeza);
			
		}else{
			//Salir
			valor = 1;
		}
	}
	freePatients(&cabeza);
	return 0;
}
