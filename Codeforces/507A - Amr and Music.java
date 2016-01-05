import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;


/**
 *
 * @author Melissa
 */
public class main {
    
    public static void main(String[] args) throws IOException{
        Scanner sc=new Scanner();
        int n,k,i;
        n=sc.nextInt();
        k=sc.nextInt();
        i=1;
        ArrayList<int[]> instrumentos=new ArrayList<>();
        
        while(i<=n){
            int[]aux={sc.nextInt(), i};
            instrumentos.add(aux);
            i++;
        }

        Collections.sort(instrumentos, (int[] o1, int[] o2) -> {
            if(o1[0]>o2[0]){
                return 1;
            }else if(o1[0]<o2[0]){
                return -1;
            }else{
                return 0;
            }
        });
        
       int horas=0;
       int aux[];
       int cant=0;
       String rta="";
       while(horas<k && instrumentos.size()>0){
           aux=instrumentos.remove(0);
           horas+=aux[0];
           if(horas<=k){
               cant++;
               if(cant==1){
                   rta=aux[1]+"";
               }else{
                   rta+=" "+aux[1];
               }
           }
       }
       
        System.out.println(cant);
        if(cant!=0){
            System.out.println(rta);
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