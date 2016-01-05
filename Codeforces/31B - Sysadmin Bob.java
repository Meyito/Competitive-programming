import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        boolean valido = true;
        String a = sc.next();
        if (a.charAt(0) == '@' || a.charAt(a.length() - 1) == '@') {
            valido = false;
        }

        if (valido) {
            String[] cadena = a.split("@");
            StringBuilder solucion = new StringBuilder();

            if (cadena.length == 1) {
                valido = false;
            } else {
                solucion.append(cadena[0]);

                String aux;

                for (int i = 1; i < cadena.length - 1; i++) {
                    aux = cadena[i];
                    if (aux.length() >= 2) {
                        solucion.append("@");
                        solucion.append(aux.charAt(0));
                        solucion.append(",");
                        solucion.append(aux.substring(1, aux.length()));
                    } else {
                        valido = false;
                        break;
                    }
                }

                if (cadena[cadena.length - 1].length() == 0) {
                    valido = false;
                } else {
                    solucion.append("@");
                    solucion.append(cadena[cadena.length - 1]);
                }

                if (valido) {
                    System.out.println(solucion);
                }

            }

        }

        if (!valido) {
            System.out.println("No solution");
        }
    }

    /**
     * CLASE para el manejo optimizado de entradas estandar en Java
     */
    static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");

        /**
         * Devuelve la siguiente linea entera en el stream.
         *
         * @return String con la linea siguiente
         * @throws IOException
         */
        public String nextLine() throws IOException {
            return br.readLine();
        }

        /**
         * Devuelve el siguiente token delimitado por espacios o saltos de
         * linea. Es decir, devuelve la siguiente palabra.
         *
         * @return String con el siguiente token
         * @throws IOException
         */
        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        /**
         * Escanea el siguiente token del stream como un entero. REQUIERE LA
         * ESCRITURA DEL MÉTODO NEXT
         *
         * @return int pasado por el input
         * @throws IOException
         */
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}