#include <bits/stdc++.h>

using namespace std;

vector<int> ady[2010];
int vis[2010];
set<int> id;
set<int> od;
int n;
set<int> alcanzables;

void init(){
	int i;
	id.clear();
	od.clear();
	for(i=0; i<=n; i++){
		vis[i]=1;
		ady[i].clear();
	}
}

void dfs(int src){
	alcanzables.insert(src);
	vis[src]=1;
	int i, dest;
	
	for(i=0; i<ady[src].size(); i++){
		dest=ady[src][i];
		if(vis[dest]==-1){
			dfs(dest);
		}
	}
	
	return;
}

int main() {
	int m, v, w, p, i, cont;
	bool flag;
	
	
	cin>>n>>m;
	while(n!=0 && m!=0){
		init();
		
		// cout<<n<<" "<<m<<endl;
		while(m>0){
			cin>>v>>w>>p;
			if(p==2){
				ady[w].push_back(v);
				od.insert(w);
				id.insert(v);
			}
			ady[v].push_back(w);
			od.insert(v);
			id.insert(w);
			m--;
		}
		
		flag=true;
		cont=0;
		
		if(od.size()!=n || id.size()!=n){
			flag=false;
		}else{
			for(i=1; i<=n; i++){
				alcanzables.clear();
				memset(vis, -1, sizeof(vis));
				dfs(i);
				if(alcanzables.size()!=n){
					flag=false; break;
				}
			}
		}
		
		if(flag){
			cout<<1<<"\n";
		}else{
			cout<<0<<"\n";
		}
		cin>>n>>m;
	}
	
	
	
	return 0;
}