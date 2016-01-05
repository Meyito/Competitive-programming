#include <bits/stdc++.h>
#define endl "\n"

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int m, n, i, j, k;
    char president, aux;
    
    cin>>n>>m>>president;
    char mesas[n][m];
    vector<char> diputados;
    vector<pair<int,int> > posicionesPresidente;
    
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>aux;
            if(aux==president){
                posicionesPresidente.push_back(make_pair(i, j));
            }
            mesas[i][j]=aux;
        }
    }

    vector<char>::iterator it;
    for(k=0; k<posicionesPresidente.size(); k++){
        i=(posicionesPresidente[k]).first;
        j=(posicionesPresidente[k]).second;
        
        if(i-1>=0){
            aux=mesas[i-1][j];
            if(aux!=president && aux!='.'){
                it = find (diputados.begin(), diputados.end(), aux);
                if (it == diputados.end()){
                    diputados.push_back(aux);
                }
            }
        }
        
        if(i+1<n){
            aux=mesas[i+1][j];
            if(aux!=president && aux!='.'){
                it = find (diputados.begin(), diputados.end(), aux);
                if (it == diputados.end()){
                    diputados.push_back(aux);
                }
            }
        }
        
        if(j-1>=0){
            aux=mesas[i][j-1];
            if(aux!=president && aux!='.'){
                it = find (diputados.begin(), diputados.end(), aux);
                if (it == diputados.end()){
                    diputados.push_back(aux);
                }
            }
        }
        
        if(j+1<m){
            aux=mesas[i][j+1];
            if(aux!=president && aux!='.'){
                it = find (diputados.begin(), diputados.end(), aux);
                if (it == diputados.end()){
                    diputados.push_back(aux);
                }
            }
        }
        
    }
    

    cout<<diputados.size()<<endl;
}