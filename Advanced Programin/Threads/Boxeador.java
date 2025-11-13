import java.util.Random;

public class Boxeador extends Thread {

    // Atributos
    private String nombre;
    private Ring ring;
    private int golpes;
    private Boxeador rival;
    private boolean noqueado;

    //Constructor
    public Boxeador(String nombre, Ring ring) {
        this.nombre = nombre;
        this.ring = ring;
        this.golpes = 0;
        this.noqueado = false;
    }

    //Setter y Getter methods
    public String getNombre() { 
        return nombre; 
    }

    public int getGolpes() { 
        return golpes; 
    }

    // Método para registrar un golpe dado por el boxeador
    public void pegar() {
        golpes++;
        rival.setNoqueado(true);
    }

    // Setter para el estado de noqueado
    public synchronized void setNoqueado(boolean noqueado) {
        this.noqueado = noqueado;
    }

    // Setter y Getter para el rival
    public void setRival(Boxeador rival) {
        this.rival = rival;
    }

    public Boxeador getRival() {
        return rival;
    }

    // Indica que este método sobrescribe el método run() de la clase Thread
    @Override 
    public void run() {
        while (ring.getGolpes() < 50) {
            if (noqueado) {
                try {
                    Thread.sleep(new Random().nextInt(250)); // Simula el tiempo de recuperación 250ms
                } catch (InterruptedException ie) {}
                noqueado = false;
            } else {
                ring.pegar(this);
                try {
                    Thread.sleep(new Random().nextInt(500)); // Simula el tiempo entre golpes 500ms
                } catch (InterruptedException ie) {}
            }
        }
    }
}
