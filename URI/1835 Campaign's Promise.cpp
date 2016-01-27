#include <bits/stdc++.h>

using namespace std;

vector<int> ady[105];
bool vis [105];
int n, m;

void init(){
	int i;
	for(i=1; i<=n; i++){
		ady[i].clear();
		vis[i]=false;
	}
}

void dfs(int src){
	int i, dest;
	vis[src]=true;
	
	for(i=0; i<ady[src].size(); i++){
		dest=ady[src][i];
		if(!vis[dest]){
			dfs(dest);
		}
	}
}

int main() {
	int x, y, rta, tc, i, j;

	 cin>>tc;
		i=1;
		while(i<=tc){
			cin>>n>>m;
			init();
			rta=0;
			while(m>0){
				cin>>x>>y;
				ady[x].push_back(y);
				ady[y].push_back(x);
				m--;
			}
			
			for(j=1; j<=n; j++){
				if(!vis[j]){
					dfs(j);
					rta++;
				}
			}
			
			if(rta==1){
				cout<<"Caso #"<<i<<": a promessa foi cumprida\n";
			}else{
				cout<<"Caso #"<<i<<": ainda falta(m) "<<rta-1<<" estrada(s)\n";
			}
			i++;
		}
		
	return 0;
}