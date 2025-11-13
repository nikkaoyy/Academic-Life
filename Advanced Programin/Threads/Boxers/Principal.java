public class Principal {

    public static void main(String args[]) {

        Ring ring = new Ring();

        // Crea los boxeadores
        Boxeador boxeador1 = new Boxeador("El churco", ring);
        Boxeador boxeador2 = new Boxeador("El tato", ring);

        // Asigna los rivales
        boxeador1.setRival(boxeador2);
        boxeador2.setRival(boxeador1);

        // Inicia el combate
        boxeador1.start();
        boxeador2.start();

        // Espera que ambos hilos terminen
        try {
            boxeador1.join();
            boxeador2.join();
        } catch (InterruptedException ie) {}

        System.out.println("Fin del combate");

        // Calcula el ganador
        String ganador;
        int golpes1 = boxeador1.getGolpes();
        int golpes2 = boxeador2.getGolpes();

        if (golpes1 > golpes2) {
            ganador = boxeador1.getNombre();
        } else if (golpes2 > golpes1) {
            ganador = boxeador2.getNombre();
        } else {
            ganador = "Empate";
        }

        System.out.println("El ganador es: " + ganador);
    }
}

