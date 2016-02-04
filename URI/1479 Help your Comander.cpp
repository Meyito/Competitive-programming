#include <bits/stdc++.h>
#define Node pair<int, long long>
using namespace std;

int n;
vector<Node> ady[1010];
int marked[1010];
long long dis[1010];
int previo[1010];

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

void init2(){
	long long max=LLONG_MAX;
    for(int j=0; j<=n; j++){
        marked[j]=0;
        previo[j]=-1;
        dis[j]=max;
    }
}

void init(){
    for(int j=0; j<=n; j++){
        ady[j].clear();
    }
}

void dijkstra(int s){
	init2();
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push(Node(s, 0));//se inserta a la cola el nodo Inicial.
    dis[s]=0;
    int actual, j, adjacent;
    long long weight;

    while(!pq.empty()){
        actual=pq.top().first;
        pq.pop();
        if(marked[actual]==0){
            marked[actual]=1;
            for(j=0; j<ady[actual].size(); j++){
                adjacent=ady[actual][j].first;
                weight=ady[actual][j].second;
                if(marked[adjacent]==0){
                    if(dis[adjacent]>dis[actual]+weight){
                         dis[adjacent]=dis[actual]+weight;
                         previo[adjacent]=actual;
                         pq.push( Node(adjacent, dis[adjacent]) );
                     }
                }
            }
        }
    }
}

int main() {
	int m,q, u, v, w, i;
	string s;
	cin>>n>>m;
	
	while(n!=0 && m!=0){
		init();
		while(m>0){
			m--;
			cin>>u>>v>>w;
			ady[u].push_back(Node(v, w));
		}
		
		cin>>q;
		while(q>0){
			cin>>s;
			if(s=="R"){
				cin>>u>>v;
				for(i=0; i<ady[u].size(); i++){
					if(ady[u][i].first==v){
						ady[u].erase(ady[u].begin()+(i));
					}
				}
			}else if(s=="I"){
				cin>>u>>v>>w;
				ady[u].push_back(Node(v, w));
			}else{
				cin>>v;
				dijkstra(1);
				if(previo[v]==-1){
					cout<<-1<<endl;
				}else{
					cout<<dis[v]<<"\n";
				}
			}
			
			q--;
		}
		cout<<"\n";
		cin>>n>>m;
	}
	return 0;
}