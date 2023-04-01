

//Deficion de variables
int cantJugadores;
int i;
int opcion, opcion2;

//Jugabilidad
int turnoEquipo = 1;
int turnoJugador = 0;
int turnos;
int turnoscont = 0;
int jugadorAtaque;

bool valor = true;
Random rand = new Random();

//Primero se pide la cantidad de jugadores
Console.Write("Ingrese la cantidad de jugadores por equipo: ");
cantJugadores = Convert.ToInt32(Console.ReadLine());

System.Console.Write("Ingrese la cantidad de turnos por jugador: ");
turnos = Convert.ToInt32(Console.ReadLine());

Console.Clear();

//Se crean los equipos
Jugador[] jugadores1 = new Jugador[cantJugadores];
Jugador[] jugadores2 = new Jugador[cantJugadores];

//Se llenan los equipos
for(i = 0; i < cantJugadores; i++){
    jugadores1[i].name = "Jugador " + Convert.ToString(i +1);
    jugadores1[i].puntaje = rand.Next(0,100);
    jugadores1[i].nivel = rand.Next(0,200);
    jugadores1[i].salud = rand.Next(50,100);

    jugadores2[i].name = "Jugador " + Convert.ToString(i+1);
    jugadores2[i].puntaje = rand.Next(0,100);
    jugadores2[i].nivel = rand.Next(0,200);
    jugadores2[i].salud = rand.Next(50,100);
}

//Comienza el juego
while(valor){
    //Verificar si se acabaron los turnos
    if(turnoscont == turnos){
        valor = ganador(jugadores1, jugadores2, cantJugadores);
        break;
    }else{
        System.Console.WriteLine("Ingrese una opcion: \n\t>> 1 para mostrar informacion de equipos \n\t>> 2 para jugar \n\t>> 3 para salir");
        opcion = Convert.ToInt32(Console.ReadLine());
        
        if(opcion == 1){
            //Mostrar informacion; 
            System.Console.WriteLine("Ingrese una opcion \n\t>> 1 para mostrar el equipo 1 \n\t>> 2 para mostrar el equipo 2");
            opcion2 = Convert.ToInt32(Console.ReadLine());
            Console.Clear();

            if(opcion2 == 1){
                //mostrar equipo 1
                printArray(jugadores1, cantJugadores);
                pause();
            }else{
                //mostrar equipo 2
                printArray(jugadores2, cantJugadores);
                pause();
            }
        }else if(opcion == 2){
            //Comineza el juego

            //Cambio de ronde se suma un turno
            if(turnoJugador == cantJugadores){

                turnoJugador = 0;
                turnoscont++;
            }
            if(turnoEquipo > 0){
                //turno equipo 1
                if(jugadores1[turnoJugador].salud > 0){
                    atacar(jugadores1, jugadores2, cantJugadores, 1);
                    
                }else{
                    System.Console.WriteLine("\nEste jugadr no tiene vida...");
                    pause();
                }
                //Cambio de turno
                turnoEquipo = turnoEquipo * -1;
            }else{
                if(jugadores2[turnoJugador].salud > 0){
                    atacar(jugadores2, jugadores1, cantJugadores, 2);
                }else{
                    System.Console.WriteLine("\nEste jugadr no tiene vida...");
                    pause();
                }
                //Cambio de turno
                turnoEquipo = turnoEquipo * -1;
                //Cambio Jugador
                turnoJugador++;
            }
        }else{
            valor = false;
        }
    }
    
}

bool ganador(Jugador[] jugadores1, Jugador[] jugadores2, int cantJugadores){
    int sumaPuntajeA = 0;
    int sumaPuntajeB = 0;

    System.Console.WriteLine("Se acabo el juego, ya no quedan mas turnos...");
    System.Console.WriteLine("\nRESUTADO:  ");
    for(i= 0; i < cantJugadores; i++){
        sumaPuntajeA = sumaPuntajeA + jugadores1[i].puntaje;
        sumaPuntajeB = sumaPuntajeA + jugadores2[i].puntaje;	
    }
    if(sumaPuntajeA == sumaPuntajeB){
        System.Console.WriteLine("Ambos equipos han empatado");
    }else if(sumaPuntajeA < sumaPuntajeB){
        System.Console.WriteLine("Ha ganado el Equipo 2");
    }else{
        System.Console.WriteLine("Ha ganado el Equipo 1");
    }
    pause();
    return false;
}

//Funcion para atacar
void atacar (Jugador[] jugadores1, Jugador[] jugadores2, int cantJugadores, int equipo){
    int ataque; 
    System.Console.WriteLine("|========| Jugador {0} Equpo "+ equipo +" es tu turno |========|", turnoJugador+1);
                    
    pause();

    System.Console.WriteLine("\nLos jugadores del Equipo 2 son: ");

    pause();

    printArray(jugadores2, cantJugadores);
    System.Console.WriteLine();

    System.Console.Write("Ingrese el numero del jugador que desee atacar: ");
    jugadorAtaque = Convert.ToInt32(Console.ReadLine()) - 1;

    //Se le quita la vida
    ataque = rand.Next(20,50);
    jugadores2[jugadorAtaque].salud = jugadores2[jugadorAtaque].salud - ataque;
    System.Console.WriteLine("\nLe ha quitado {0} de vida al jugaodor {1} del equipo 2", ataque, jugadorAtaque+1);
    pause();
}

//funcioon para hacer uns pausa en la consola
void pause(){
    System.Console.Write("\nPresione cualquier tecla para continuar...");
    Console.ReadKey();   
    Console.Clear();
}

//Funcion para imprimir el arreglo de jugadores
void printArray(Jugador[] jugadores, int cantidad){
    int i;
	
	for(i= 0; i < cantidad; i++){
		Console.WriteLine("|========| Jugador {0} |========|", i+1);
		Console.WriteLine("  >> Nombre: " + jugadores[i].name);
		Console.WriteLine("  >> Nivel: " + jugadores[i].nivel);
		Console.WriteLine("  >> Porcentaje de salud: " + jugadores[i].salud);
		Console.WriteLine("  >> Puntaje: " + jugadores[i].puntaje + "\n");
		
	}
}   

struct Jugador{
    public string name;
    public int nivel;
    public int salud;
    public int puntaje; 

}
