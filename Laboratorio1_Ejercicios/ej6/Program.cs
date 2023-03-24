// See https://aka.ms/new-console-template for more information

Jugador jugador1 = new Jugador();
jugador1.nombre = "Valehica";
jugador1.vida = 50;
jugador1.tipo = "Mago";
jugador1.poder = "Hechizos de fuego";
jugador1.velocidad = 2;

bool valor = true;

while(valor){
    jugador1.imrpimir();
    System.Console.WriteLine("Escoja un opcion: \n\t>> 1 para recuperar vida \n\t>> 2 para atacar");
    string? opcion = Console.ReadLine();

    if(opcion == "1"){
        jugador1.recuperarEnergia();
    }else if(opcion == "2"){
        jugador1.atacar();
    }else{
        System.Console.WriteLine("La opcion ingresada es incorrecta..\n");
    }

}

