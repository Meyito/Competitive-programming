#include <bits/stdc++.h>
using namespace std;

vector<int> ady[55];
int marked[55];
int previous[55];
int dfs_low[55];
int dfs_num[55];
int n, e;
int dfsRoot,rootChildren,cont;
vector<pair<int,int>> bridges;

void init(){
    bridges.clear();
    cont=0;
    int i;
    for(i=1; i<=n; i++){
        ady[i].clear();
        marked[i]=0;
        previous[i]=-1;
    }
}

void dfs(int u){
    dfs_low[u]=dfs_num[u]=cont;
    cont++;
    marked[u]=1; 
    int j, v;

    for(j=0; j<ady[u].size(); j++){
        v=ady[u][j];
        if(marked[v]==0){
            previous[v]=u;
            //para el caso especial 
            if(u==dfsRoot){
                rootChildren++;
            }
            dfs(v);
            
            //Bridges
            if(dfs_low[v]>dfs_num[u]){
                bridges.push_back(make_pair(min(u,v),max(u,v)));
            }
            dfs_low[u]=min(dfs_low[u], dfs_low[v]);
        }else if(v!=previous[u]){ //Arco que no sea backtrack
            dfs_low[u]=min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int p, x, y;
    
    while(cin>>n){
    	cin>>p;
    	init();
    	while(p>0){
    		cin>>x>>y;
    		ady[x].push_back(y);
    		ady[y].push_back(x);
    		p--;
    	}
    	
    	cont=0;
    	dfsRoot=1;
    	rootChildren=0;
    	dfs(1);
    	cout<<bridges.size()<<"\n";
    }
    
	return 0;
}