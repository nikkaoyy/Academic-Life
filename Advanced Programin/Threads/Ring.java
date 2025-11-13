public class Ring {

    private int golpes;

    public Ring() {
        golpes = 0; //Inicializamos en 0
    }

    public int getGolpes() {
        return golpes; //Devuelve total de golpes dados
    }

    // La sincronización controla el acceso concurrente de los hilos al recurso compartido.
    public synchronized void pegar(Boxeador boxeador) {
        boxeador.pegar(); // El boxeador da un golpe
        golpes++; // Incrementa el total de golpes dados en el ring
        System.out.println("Pegada de Boxeador: " + boxeador.getNombre() + " (Golpes dados: " + boxeador.getGolpes() + ")");
    }
}
