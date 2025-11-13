import java.io.*;

public class Example1 {
    public static void main(String[] args) throws IOException {
        InputStreamReader inStream;
        BufferedReader in;
        String segSocial, nombre, strEdad;
        int edad;

        inStream = new InputStreamReader(System.in);
        in = new BufferedReader(inStream);

        segSocial = in.readLine();
        nombre = in.readLine();
        strEdad = in.readLine();
        edad = Integer.parseInt(strEdad);
    }
}
