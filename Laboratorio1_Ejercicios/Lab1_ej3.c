//Ejercicio 3 Laboratorio 1 Algoritmos
//Pantalla de carga

int main(){
	char carga[2] = "I";
	int ext = 20; 
	int carga_n = 0; 
	int i;
	
	while(carga_n <= ext){
		
		printf("\n\n\t       CARGANDO...\n\n");
		
		printf("\t[");
		for (i = 0; i < carga_n; i++){
			printf("%s", carga);
		}
		for (i = 0; i < ext - carga_n; i++){
			printf(" ");
		}		
		carga_n++;
		printf("]");
		sleep(1);
		system("cls");
	}
	
	
	return 0; 
} 
