class Vehiculo{
    public string fabricante = string.Empty;
    public string modelo = string.Empty;
    public DateTime age = new DateTime(); 
    public double velocidad = 0.7; 
    public double maniobrabilidad = 0.8; 

    public void printVehiculo(){
        System.Console.WriteLine("|============| INFORMACION |============|");
        System.Console.WriteLine("\t>> Fabricante: " + this.fabricante);
        System.Console.WriteLine("\t>> Modelo: " + this.modelo);
        System.Console.WriteLine("\t>> Año: " + this.age.ToString("MMMM dd, yyyy"));
        System.Console.WriteLine("\t>> Porcentaje de Velocidad: " + this.velocidad);
        System.Console.WriteLine("\t>> Porcentaje de Maniobralidad: " + this.maniobrabilidad);
        System.Console.WriteLine();
    }
}