#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ady[1005];
map<int,int> alcanzados;

void alcanzables(int s){
	int i;
	for(i=0; i<ady[s].size(); i++){
		alcanzados[ady[s][i]]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int i,j, rta;
	bool flag;
	char x;
	map<int,int> aux;
	vector<int> tam;
	
	cin>>n;
	int vis[n];
	flag=true;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>x;
			if(i==j && x=='D')	flag=false;
			if(x=='S'){
				ady[i].push_back(j);
			}
		}
	}
	
	rta=0;

	if(flag){
		memset(vis, 0, sizeof(vis));
		for(i=0; i<n; i++){
			if(vis[i]==0){
				alcanzados.clear();
				alcanzables(i);
				
				aux=alcanzados;
				map<int,int>::iterator it;
				for(it=aux.begin(); it!=aux.end(); it++){
					if(it->first!=i){
						alcanzables(it->first);
						if(alcanzados.size()!=aux.size()){
							flag=false;
							break;
						}
					}	
				}
				
				
				for(it=alcanzados.begin(); it!=alcanzados.end(); it++){
					if(it->second!=aux.size()){
						flag=false;
						break;
					}
					vis[it->first]=1;
				}
				
				if(flag){
					rta++;
					tam.push_back(aux.size());
				}
			}
		}
	}
	
	if(flag){
		cout<<rta<<"\n";
		sort(tam.begin(), tam.end());
		i=tam.size()-1;
		cout<<tam[i];
		i--;
		while(i>=0){
			cout<<" "<<tam[i];
			i--;
		}
		cout<<"\n";
	}else{
		cout<<"-1\n";
	}
	
	return 0;
}
