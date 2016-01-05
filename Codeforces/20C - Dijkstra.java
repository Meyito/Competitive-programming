import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 *
 * @author Meli
 */
public class Main {

    static int v, e;
    static ArrayList<Node> ady[] = new ArrayList[100001];
    static int visitado[] = new int[100001];
    static long distancia[] = new long[100001];
    static int previo[] = new int[100001];

    public static void main(String[] args) throws java.lang.Exception {
        int i;
        Scanner sc = new Scanner();
        v = Integer.parseInt(sc.next());
        e = Integer.parseInt(sc.next());
        init();
        i = 0;

        int src, dest, peso;

        while (i < e) {
            src = Integer.parseInt(sc.next());
            dest = Integer.parseInt(sc.next());
            peso = Integer.parseInt(sc.next());
            ady[src].add(new Node(dest, peso));
            ady[dest].add(new Node(src, peso));
            i++;
        }

        dijkstra();
        imprimirRuta(v);
    }

    static void init() {
        long max = Long.MAX_VALUE;

        for (int j = 1; j <= v; j++) {
            visitado[j] = 0;
            previo[j] = -1;
            distancia[j] = max;
            ady[j] = new ArrayList<Node>();
        }
    }

    static void dijkstra() {
        //PriorityQueue cPrioridad = new PriorityQueue();
        PriorityQueue<Node> cPrioridad=new PriorityQueue<Node>();
        cPrioridad.add(new Node(1, 0));//se inserta a la cola el nodo Inicial.
        distancia[1] = 0;
        int actual, j, adyacente;
        long peso;
        Node x;

        while (cPrioridad.size() > 0) {
            actual = cPrioridad.peek().adyacente;
            if (visitado[actual] == 0) {
                visitado[actual] = 1;
                for (j = 0; j < ady[actual].size(); j++) {
                    adyacente = ady[actual].get(j).adyacente;
                    peso = ady[actual].get(j).costo;
                    if (visitado[adyacente] == 0) {
                        if (distancia[adyacente] > distancia[actual] + peso) {
                            distancia[adyacente] = distancia[actual] + peso;
                            previo[adyacente] = actual;
                            cPrioridad.add(new Node(adyacente, distancia[adyacente]));
                        }
                    }
                }
            }
            cPrioridad.poll();
        }
    }

    static void imprimirRuta(int posicion) {
        if (previo[posicion] == -1) {
            if (posicion != 1) {
                System.out.println("-1");
            } else {
                System.out.print(posicion + " ");
            }
        } else {
            imprimirRuta(previo[posicion]);
            if (posicion == v) {
                System.out.println(v);
            } else {
                System.out.print(posicion + " ");
            }
        }
    }

    static class Node implements Comparable<Node> {

        public int adyacente;
        public long costo;

        public Node(int ady, long c) {
            this.adyacente = ady;
            this.costo = c;
        }

        @Override
        public int compareTo(Node o) {
            if (this.costo >= o.costo) {
                return 1;
            } else {
                return -1;
            }
        }
    }

    static class Scanner {

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer st = new StringTokenizer("");
        int espacios = 0;

        public String nextLine() throws IOException {
            if (espacios > 0) {
                espacios--;
                return "";
            } else if (st.hasMoreTokens()) {
                StringBuilder salida = new StringBuilder();
                while (st.hasMoreTokens()) {
                    salida.append(st.nextToken());
                    if (st.countTokens() > 0) {
                        salida.append(" ");
                    }
                }
                return salida.toString();
            }
            return br.readLine();
        }

        public String next() throws IOException {
            espacios = 0;
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public boolean hasNext() throws IOException {
            while (!st.hasMoreTokens()) {
                String linea = br.readLine();
                if (linea == null) {
                    return false;
                }
                if (linea.equals("")) {
                    espacios++;
                }
                st = new StringTokenizer(linea);
            }
            return true;
        }
    }

}