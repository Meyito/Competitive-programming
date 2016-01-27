#include <bits/stdc++.h>
 
using namespace std;
 
int n,m;
char mapa[52][52];
map<pair<int, int>, bool> visitados; 
map<pair<int, int>, bool> contaminados; 
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
 
void dfs(int y, int x){
    pair<int,int> aux=make_pair(y, x);
    visitados[aux]=true;
    int i, xx, yy;
     
    for(i=0; i<4; i++){
        xx=x+dx[i];
        yy=y+dy[i];
         
        aux=make_pair(yy, xx);
        if(xx>=0 && xx<m && yy>=0 && yy<n && !visitados[aux] && mapa[yy][xx]!='X'){
            mapa[yy][xx]='T';
            dfs(yy,xx);
        }
    }
}
 
int main(){
    int i,j;
    pair<int,int> aux;
    cin>>n>>m;
    while(n!=0 && m!=0){
        visitados.clear();
        contaminados.clear();
         
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                cin>>mapa[i][j];
                if(mapa[i][j]=='T'){
                    visitados[make_pair(i,j)]=false;
                    contaminados[make_pair(i,j)]=false;
                }
            }
        }
         
        map<pair<int, int>, bool >::iterator it;
         
        for (it=contaminados.begin(); it!=contaminados.end(); ++it){
            if(!it->second){
                aux=it->first;
                dfs(aux.first, aux.second);
            }
        }
         
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                cout<<mapa[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
        cin>>n>>m;
    }
    return 0;
}