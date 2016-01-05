import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class prueba {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        String cad1, cad2, cad3, c1, c2, c3, c4, c5, c6, aux;
        cad1 = sc.next();
        cad1 = cad1.replaceAll(";|\\-|\\_", "");
        cad2 = sc.next();
        cad2 = cad2.replaceAll(";|\\-|\\_", "");
        cad3 = sc.next();
        cad3 = cad3.replaceAll(";|\\-|\\_", "");
        c1 = cad1 + cad2 + cad3;
        c2 = cad1 + cad3 + cad2;
        c3 = cad2 + cad1 + cad3;
        c4 = cad2 + cad3 + cad1;
        c5 = cad3 + cad1 + cad2;
        c6 = cad3 + cad2 + cad1;
        int n = sc.nextInt();
        while (n > 0) {
            aux = sc.next();
            aux = aux.replaceAll(";|\\-|\\_", "");
            if (aux.equalsIgnoreCase(c1) || aux.equalsIgnoreCase(c2) || aux.equalsIgnoreCase(c3)
                    || aux.equalsIgnoreCase(c4) || aux.equalsIgnoreCase(c5) || aux.equalsIgnoreCase(c6)) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
            }
            n--;
        }
    }

    static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

    }
}