import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author Melissa
 */
public class main {
    public static void main(String [] args) throws IOException{
        
        Scanner sc=new Scanner();
        StringBuilder cambio=new StringBuilder(sc.next());
        int aux, aux2, i, fin, indice;
        fin=cambio.charAt(cambio.length()-1)-48;
        aux2=-1;
        aux=0;
        indice=0;
        for(i=0; i<cambio.length(); i++){
            aux=cambio.charAt(i)-48;
            if(aux%2==0){
                aux2=aux;
                indice=i;
                if(aux2<fin){
                    break;
                }
            }
        }
        if(aux!=fin || aux2!=-1){
            cambio.replace(cambio.length()-1, cambio.length(), aux2+"");
            cambio.replace(indice, indice+1, fin+"");
            System.out.println(cambio);
        }else{
            System.out.println("-1");
        }
        
        
    }
    static class Scanner {

        InputStreamReader en = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(en);
        StringTokenizer st = new StringTokenizer("");

        /*---------------------METODOS INDISPENSABLES------------------*/
        /**
         * Recibe linea a linea de la entrada estandar
         *
         * @return un string con la linea recibida
         * @throws IOException
         */
        public String nextLine() throws IOException {
            return in.readLine();
        }

        /**
         * Recibe un entero o rompe la ejecución si no hay mas datos
         *
         * @return entero con el numero recibido
         * @throws IOException
         */
        public int nextIntOrQuit() throws IOException {
            Integer n = nextInteger();
            if (n == null) {
                System.exit(0);
            }
            return n.intValue();
        }

        /**
         * Lee una palabra, separada por espacio o salto de linea
         *
         * @return string con la palabra
         * @throws IOException
         */
        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String l = nextLine();
                if (l == null) {
                    return null;
                }
                st = new StringTokenizer(l);
            }
            return st.nextToken();
        }

        /**
         * Lee una palabra, separada por espacio o salto de linea, rompe la
         * ejecución si no existe la palabra
         *
         * @return string con la palabra
         * @throws IOException
         */
        public String nextOrQuit() throws IOException {
            while (!st.hasMoreTokens()) {
                String l = nextLine();
                if (l == null) {
                    System.exit(0);
                }
                st = new StringTokenizer(l);
            }
            return st.nextToken();
        }

        /**
         * Metodo que retorna el siguiente entero recibido por input estandar
         * IMPORTANTE: Retorna el dato con tipo primitivo int
         *
         * @return entero recibido por entrada estandar
         * @throws IOException
         */
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        /**
         * Recibe el siguiente entero, no como tipo primitivo sino como tipo
         * Integer
         *
         * @return entero del tipo Integer (no primitivo)
         * @throws IOException
         */
        public Integer nextInteger() throws IOException {
            String s = next();
            if (s == null) {
                return null;
            }
            return Integer.parseInt(s);
        }
    }
}