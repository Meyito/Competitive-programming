https://www.urionlinejudge.com.br/judge/en/problems/view/1862

#include <bits/stdc++.h>

using namespace std;

vector<int> ady[1000];
int vis[1000];
int n, aux;
bool flag;
map<int, int> alcanzados;
map<int, bool> markeds;
map<int, bool> pass;

void dfs(int i){
    cout<<i<<endl;
    alcanzados[i]++;
    int j, dest;
    
    for(j=0; j<ady[i].size(); j++){
        dest=ady[i][j];
        alcanzados[dest]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    char x;
    int i,j, rta;
    vector<int> tam;
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>x;
            if(x=='S'){
                ady[i].push_back(j) ;
            }
        }
    }
    
    rta=0;
    flag=true;
    
    for(i=0; i<n; i++){
        cout<<i<<"-"<<markeds[i]<<endl;
        // if(!markeds[i]){
        //  cout<<i<<endl;
        //  alcanzados.clear();
        //  dfs(i);
            
        //  map<int, int>::iterator it;
        //  markeds[i]=true;
        //  aux=alcanzados.size();
        //  for(it=alcanzados.begin(); it!=alcanzados.end(); it++){
        //      if(it->first!=i){
        //          alcanzados.clear();
        //          dfs(it->first);
        //          if(alcanzados.size()!=aux){
        //              flag=false;
        //              break;
        //          }else{
        //              markeds[it->first]=true;
        //          }
        //      }
        //  }
            
        //  if(!flag){
        //      cout<<"buenas o.O"<<endl;
        //      break;
        //  }else{
        //      cout<<"holiiiii"<<endl;
        //      rta++;
        //      tam.push_back(alcanzados.size());
        //  }
        // }
    }
    
    if(!flag){
        cout<<"-1\n";
    }else{
        cout<<rta<<"\n";
        sort(tam.begin(), tam.end());
        cout<<tam.size();
        // i=tam.size()-1;
        // cout<<tam[i];
        // i--;
        // while(i>=0){
        //  cout<<" "<<tam[i];
        //  i--;
        // }
    }
    
    return 0;
}