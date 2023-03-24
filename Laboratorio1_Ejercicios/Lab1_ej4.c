//Ejercicio 4 Laboratorio 1 Algoritmos

void printTablero(int n, int tablero[n][n]){
	int i, k; 
	for(i = 0; i < n; i++){
		for(k = 0; k < n; k++){
			if(tablero[i][k] == 0){
				printf(" ");
			}else if(tablero[i][k] == 1){
				printf("X");
			}else if(tablero[i][k] == 2){
				printf("O");
			}
			printf("|");
		}
		printf("\n");
	}
}

int main(){
	int n = 3;
	int arrayTablero[n][n];
	int jugador = 1; 
	int valor = 1; 
	int columna, fila, i, k, opcionMenu; 
	
	//Inicializacion del tablero
	for(i = 0; i < n; i++){
		for(k = 0; k < n; k++){
			arrayTablero[i][k] = 0; 
		}
	}
	
	//Presentacion del juego
	printf("|==============================|\n");
	printf("BIENVENIDO AL JUEGO DEL GATO \n");
	printf("|==============================|\n");
	system("pause");
	system("cls"); 
	
	//LLenado del tablero
	while(valor == 1){
		printf("Ingrese una opcion: \n\t>> 1 para jugar \n\t>> 2 para borrar una jugada\n");
		scanf("%d", &opcionMenu);
		
		if(opcionMenu == 1){
			if(jugador > 0){
				printf("\nJugador 1, ES TU TURNO\n");
				printf("Ingrese la columna en la que desee: ");
				scanf("%d", &columna);
				printf("Ingrese la fila en la que desee: ");
				scanf("%d", &fila);
				printf("\n");
				
				arrayTablero[fila-1][columna-1] = 1;
				jugador = jugador * -1; 
				
			}else if(jugador < 0){
				printf("\nJugador 2, ES TU TURNO\n");
				printf("Ingrese la columna en la que desee: ");
				scanf("%d", &columna);
				printf("Ingrese la fila en la que desee: ");
				scanf("%d", &fila);
				printf("\n");
				
				arrayTablero[fila-1][columna-1] = 2;
				jugador = jugador * -1; 
				
			}
		}else if(opcionMenu == 2){
			printf("\nEliminar un ajugada\n");
				printf("Ingrese la columna en la que desee: ");
				scanf("%d", &columna);
				printf("Ingrese la fila en la que desee: ");
				scanf("%d", &fila);
				printf("\n");	
				
				arrayTablero[fila-1][columna-1] = 0;
		}else{
			printf("La opcion ingresada es incorrecta...\n");
		}
		
		printTablero(n, arrayTablero);
		system("pause");
		system("cls");
	}
	
	return 0; 
}
