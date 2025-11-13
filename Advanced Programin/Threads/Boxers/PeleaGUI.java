import javax.swing.*;
import java.awt.*;

public class PeleaGUI extends JFrame {

    private JLabel lblGolpes1, lblGolpes2, lblEstado, lblGanador;
    private JProgressBar barra1, barra2;
    private Ring ring;
    private Boxeador boxeador1, boxeador2;

    public PeleaGUI() {
        setTitle("Simulación de Boxeo");
        setSize(450, 400); // Aumenté el tamaño para acomodar todos los componentes
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Cierra la aplicación al cerrar la ventana
        setLocationRelativeTo(null); // Centra la ventana en la pantalla
        
        // Cambié a BorderLayout para mejor organización
        setLayout(new BorderLayout(10, 10));
        
        // Panel principal con padding
        JPanel mainPanel = new JPanel(new GridLayout(7, 1, 5, 5)); // 7 filas, 1 columna, espacio vertical y horizontal de 5px
        mainPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10)); // Padding alrededor del panel

        JLabel lblTitulo = new JLabel("Combate: El churco vs El tato", SwingConstants.CENTER);
        lblTitulo.setFont(new Font("Calibri", Font.BOLD, 20));

        lblGolpes1 = new JLabel("El churco: 0 golpes", SwingConstants.CENTER);
        lblGolpes2 = new JLabel("El tato: 0 golpes", SwingConstants.CENTER);

        // Configurar mejor las barras de progreso
        barra1 = new JProgressBar(0, 50);
        barra2 = new JProgressBar(0, 50);
        barra1.setForeground(Color.RED);
        barra2.setForeground(Color.BLUE);
        barra1.setStringPainted(true); // Mostrar el valor numérico
        barra2.setStringPainted(true);
        barra1.setValue(0);
        barra2.setValue(0);

        lblEstado = new JLabel("¡La pelea está por comenzar!", SwingConstants.CENTER);
        lblGanador = new JLabel("", SwingConstants.CENTER);
        lblGanador.setFont(new Font("Arial", Font.BOLD, 16));
        lblGanador.setForeground(Color.RED);

        // Agregar componentes en orden correcto
        mainPanel.add(lblTitulo);
        mainPanel.add(lblGolpes1);
        mainPanel.add(barra1);
        mainPanel.add(lblGolpes2);
        mainPanel.add(barra2);
        mainPanel.add(lblEstado);
        mainPanel.add(lblGanador);

        add(mainPanel, BorderLayout.CENTER);

        setVisible(true);

        iniciarPelea();
    }

    private void iniciarPelea() {
        ring = new Ring();
        boxeador1 = new Boxeador("El churco", ring);
        boxeador2 = new Boxeador("El tato", ring);

        boxeador1.setRival(boxeador2);
        boxeador2.setRival(boxeador1);

        // Hilo separado para la simulación de la pelea
        Thread peleaThread = new Thread(() -> {
            boxeador1.start();
            boxeador2.start();

            // Monitorear el progreso de la pelea
            while (ring.getGolpes() < 50 && (boxeador1.isAlive() || boxeador2.isAlive())) {
                SwingUtilities.invokeLater(() -> {
                    actualizarGUI();
                });
                
                try {
                    Thread.sleep(100); // Actualización más frecuente para mejor visualización
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                }
            }

            // Esperar a que ambos boxeadores terminen
            try {
                if (boxeador1.isAlive()) boxeador1.join();
                if (boxeador2.isAlive()) boxeador2.join();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            // Mostrar resultado final
            SwingUtilities.invokeLater(() -> {
                mostrarResultado();
            });
        });
        
        peleaThread.start();
    }
    
    private void actualizarGUI() {
        lblGolpes1.setText("El churco: " + boxeador1.getGolpes() + " golpes");
        lblGolpes2.setText("El tato: " + boxeador2.getGolpes() + " golpes");
        barra1.setValue(boxeador1.getGolpes());
        barra2.setValue(boxeador2.getGolpes());
        lblEstado.setText("Total golpes: " + ring.getGolpes() + " / 50");
    }
    
    private void mostrarResultado() {
        int g1 = boxeador1.getGolpes();
        int g2 = boxeador2.getGolpes();
        
        if (g1 > g2) {
            lblGanador.setText("¡GANADOR: El churco con " + g1 + " golpes!");
            lblGanador.setForeground(Color.RED);
        } else if (g2 > g1) {
            lblGanador.setText("¡GANADOR: El tato con " + g2 + " golpes!");
            lblGanador.setForeground(Color.BLUE);
        } else {
            lblGanador.setText("¡EMPATE! Ambos con " + g1 + " golpes");
            lblGanador.setForeground(Color.ORANGE);
        }
        lblEstado.setText("¡Fin del combate!");
        
        // Deshabilitar las barras al finalizar
        barra1.setEnabled(false);
        barra2.setEnabled(false);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new PeleaGUI();
        });
    }
}
