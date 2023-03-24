class Jugador{
    public string tipo = string.Empty;
    public string nombre = string.Empty;
    public int vida = 100;
    public string poder = string.Empty;
    public int velocidad = 1; 

    public void imrpimir(){
        System.Console.WriteLine("|====| INFORMACION DEL JUGADOR |====|");
        System.Console.WriteLine("\t>> Tipo: " + this.tipo);
        System.Console.WriteLine("\t>> Nombre: " + this.nombre);
        System.Console.WriteLine("\t>> Vida: " + this.vida);
        System.Console.WriteLine("\t>> Poder: " + this.poder);
        System.Console.WriteLine("\t>> Velocidad : " + this.velocidad);
        System.Console.WriteLine();

    }
    public void recuperarEnergia(){
        this.vida = this.vida + 10; 
        System.Console.WriteLine("Has recuperad 10 de vida...");
    }

    public void atacar(){
        System.Console.WriteLine("Has lanzado un hechizo...");
    }

}