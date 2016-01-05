#include <bits/stdc++.h>
#define endl "\n"
#define Node pair<int,long long> //(Vertice adyacente, peso)

using namespace std;

int v,e;
vector<Node> ady[100001];
int visitado[100001];
long long distancia[100001];
int previo[100001];

class cmp
{
public:
    bool operator()(Node n1,Node n2)
    {

      if(n1.second>n2.second)
      return true;
      else
      return false;
    }
};

int init(){
    long long max=LLONG_MAX;
    
    for(int j=1; j<=v; j++){
        visitado[j]=0;
        previo[j]=-1;
        distancia[j]=max;
    }
    return 0;
}

void dijkstra(){
    priority_queue< Node , vector<Node> , cmp > cPrioridad;
    cPrioridad.push(Node(1, 0));//se inserta a la cola el nodo Inicial.
    distancia[1]=0;
    int actual, j, adyacente;
    long long peso;
    while(!cPrioridad.empty()){
        actual=cPrioridad.top().first;
        if(visitado[actual]==0){
            visitado[actual]==1;
            for(j=0; j<ady[actual].size(); j++){
                adyacente=ady[actual][j].first;
                peso=ady[actual][j].second;
                if(visitado[adyacente]==0){
                    if(distancia[adyacente]>distancia[actual]+peso){
                         distancia[adyacente]=distancia[actual]+peso;
                         previo[adyacente]=actual;
                         cPrioridad.push(Node(adyacente, distancia[adyacente]));
                     }
                }
            }
        }
        cPrioridad.pop();
    }
}

void imprimirRuta(int posicion){
    if(previo[posicion]==-1){
        if(posicion!=1){
            cout<<-1<<endl;
        }else{
            cout<<posicion<<" ";
        }
    }else{
        imprimirRuta(previo[posicion]);
        if(posicion==v){
            cout<<v<<endl;
        }else{
            cout<<posicion<<" ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int i;
    cin>>v>>e;
    init();
    i=0;
    
    int src, dest, peso;
    
    while(i<e){
        cin>>src>>dest>>peso;
        ady[src].push_back(Node(dest, peso));
        ady[dest].push_back(Node(src, peso));
        i++;
    }
    
    dijkstra();
    imprimirRuta(v);

}