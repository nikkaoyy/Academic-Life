import java.net.InetAddress;
import java.net.UnknownHostException;

public class PruebaSockets {

    public static void main(String[] args) {
        try {
            // Obtener la direccion IP y el nombre del host de un sitio web

            System.out.println("URL & Direccion IP: "); // Adjuntamos el nombre del host
            InetAddress direccion = InetAddress.getByName("www.udistrital.edu.co"); // Cambiamos a la direccion IP
            System.out.println(direccion); // Imprimimos la direccion IP

            System.out.println("Direccion IP: "); // Imprimimos la dirección IP obtenida anteriormente
            int temp = direccion.toString().indexOf('/'); // Buscamos la posición del carácter '/'
            direccion = InetAddress.getByName(direccion.toString().substring(temp + 1)); // Obtenemos la dirección IP
            System.out.println(direccion); // Imprimimos la dirección IP

            System.out.println("Nombre & Direccion IP actual de LocalHost"); // Obtenemos la dirección IP y el nombre del host del localhost
            direccion = InetAddress.getLocalHost(); // Obtenemos la direcciópn del LocalHost
            System.out.println(direccion); // Imprimimos la dirección del LocalHost

            System.out.println("Direccion IP del LocalHost: "); // Imprimimos la dirección IP del LocalHost
            temp = direccion.toString().indexOf('/'); // Buscamos la posición del carácter '/'
            direccion = InetAddress.getByName(direccion.toString().substring(temp + 1)); // Obtenemos la dirección IP del LocalHost
            System.out.println(direccion); // Imprimimos la dirección IP del LocalHost

            System.out.println("Nombre actual de LocalHost"); // Imprimimos el nombre del host del LocalHost
            System.out.println(direccion.getHostName()); // Imprimimos el nombre del host del LocalHost

            System.out.println("Direccion IP actual de LocalHost "); // Imprimimos la dirección IP actual del LocalHost
            byte[] bytes = direccion.getAddress(); // Obtenemos la dirección IP en bytes
            for (int cnt = 0; cnt < bytes.length; cnt++) { // Recorremos los bytes de la dirección IP
                int uByte = bytes[cnt] < 0 ? bytes[cnt] + 256 : bytes[cnt]; // Convertimos el byte a un valor sin signo
                System.out.print(uByte + " "); // Imprimimos el valor sin signo
            }

            System.out.println();

        } catch (UnknownHostException e) {
            // Capturamos la excepción en caso de que no se pueda resolver el host
            System.out.println(e); // Imprimimos la excepción
            System.out.println("Debes estar conectado para que esto funcione bien.");
        }
    }
}
