#include <bits/stdc++.h>

using namespace std;

vector<int> ady[52];
bool vis[52];
int n, v, rta;

void init(){
	int i;
	for(i=0; i<=v; i++){
		vis[i]=false;
		ady[i].clear();
	}
}

void dfs(int src){
	vis[src]=true;
	int i, dest;
	
	for(i=0; i<ady[src].size(); i++){
		dest=ady[src][i];
		if(!vis[dest]){
			rta++;
			dfs(dest);
		}
	}
	
	if(src!=n){
		rta++;
	}
	
	return;
}

int main() {
	int tc,e, src, dest;
	cin>>tc;
	while(tc>0){
		cin>>n>>v>>e;
		init();
		
		while(e>0){
			cin>>src>>dest;
			ady[src].push_back(dest);
			ady[dest].push_back(src);
			e--;
		}
		
		rta=0;

		dfs(n);
		cout<<rta<<"\n";
	
		tc--;
	}
	
	
	
	return 0;
}