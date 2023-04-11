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
		
		while(nodoActual->sig != NULL){
			nodoActual = nodoActual->sig;
		}
		
		nodoActual->sig = newNodo;
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

//modificar temperatura
Patient recordTemperature(Patient **cabeza){
	//crear un nuevo patient con el puntero cabeza
	Patient* nodo_actual = *cabeza;
	
	int indice, i, indice_temp;
	float auxTemp;
	
	printf("\nIngrese el numero del paciente al que quiere registrar nueva temperatura: ");
	scanf("%d", &indice-1);
	
	while (nodo_actual != NULL && i < indice) {
        nodo_actual = nodo_actual->sig;
        i++;
    }

    if (nodo_actual != NULL) {
		for(i = 0; i < MAXTEMP; i++){
			if(nodo_actual->temperature[i] == 0){
				indice_temp = i;
				break;
			}
		}
		
		printf("Ingreso de temperatura de paciente (si ya no desea ingresar mas dias ingrese el valor 0): \n");
		for(i = indice_temp; i < MAXTEMP; i++){
			printf("\t>> temperatura dia %d: ", i + 1); 
			scanf("%f", &auxTemp);
			
			if(auxTemp == 0){
				break;
			}else{
				nodo_actual->temperature[i] = auxTemp;
			}
		}    
    }
    
    system("cls");

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
		printf("Ingrese una opcion \n\t>> 1 para agregar un paciente \n\t>> 2 para agregar una temperatura a un paciente \n\t>> 3 para imprimir la lista de pacientes \n\t>> 4 para dar de alta a un paciente \n\t>> 5 para salir\n");
		scanf("%d", &opcion);
		system("cls");
		
		if(opcion == 1){
			//Se ingresa un paciente 
			addPatient(&cabeza, &cont);
			
		}else if(opcion == 2){
			//Agregar temperatura a un paciente 
			//printPatients(&point, cant);
			recordTemperature(&cabeza);
			
			
		}else if(opcion == 3){
			//Se imprime a lista
			printPatients(cabeza);
			system("pause");
			system("cls");
		}else if(opcion == 4){
			cabeza = dischargePatient(&cabeza);
		}else{
			//Salir
			valor = 1;
		}
	}
	freePatients(&cabeza);
	return 0;
}
