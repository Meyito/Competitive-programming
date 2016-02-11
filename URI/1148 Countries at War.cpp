#include <bits/stdc++.h>
#define Node pair<int,long long>

using namespace std;

int v,e;
int ady[505][505];
int marked[5005];
long long dist[505];
int ant[505];

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

void clean(){
    for(int j=0; j<=v; j++){
        marked[j]=0;
        ant[j]=-1;
        dist[j]=-1;
    }
}

void init(){
    for(int j=0; j<=v; j++){
        memset(ady[j], -1, sizeof(ady[j]) );
    }
}

void dijkstra(int s){
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push(Node(s, 0));//se inserta a la cola el nodo Inicial.
    dist[s]=0;
    int actual, j, adjacent;
    long long weight;

    while(!pq.empty()){
        actual=pq.top().first;
        pq.pop();
        if(marked[actual]==0){
            marked[actual]=1;
            for(j=1; j<=v; j++){
            	if(ady[actual][j]!=-1){
            		adjacent=j;
	                weight=ady[actual][j];
	                if(marked[adjacent]==0){
	                    if(dist[adjacent]==-1 || dist[adjacent]>dist[actual]+weight){
	                         dist[adjacent]=dist[actual]+weight;
	                         ant[adjacent]=actual;
	                         pq.push(Node(adjacent, dist[adjacent]));
	                     }
	                }
            		
            	}
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int s,d,p, q;
	cin>>v>>e;
	while(v!=0){
		init();
		while(e>0){
			cin>>s>>d>>p;
			if(ady[d][s]!=-1){
				ady[d][s]=0;
				ady[s][d]=0;
			}else{
				ady[s][d]=p;
			}
			e--;
		}
		
		cin>>q;
		while(q>0){
			cin>>s>>d;
			clean();
			dijkstra(s);
			if(dist[d]==-1){
				cout<<"Nao e possivel entregar a carta\n";
			}else{
				cout<<dist[d]<<"\n";
			}
			q--;
		}
		cout<<"\n";
		cin>>v>>e;
	}
	return 0;
}