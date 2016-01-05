#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
long long clon[500][500];
long long orden[500];
long long result[500];

int n, i, j, y;


void floydWarshall(){
    int x=0;
    int aux, k;
    long long rta=0;

    k=orden[y];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){

            aux=clon[orden[i]][k]+clon[k][orden[j]];
            if(aux<clon[orden[i]][orden[j]]){
                clon[orden[i]][orden[j]]=aux;
            }
        if(i<=y and j<=y)
            rta+=clon[orden[i]][orden[j]];
        }
    }
    result[y]=rta;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>clon[i][j];
        }
    }

    for(i=n-1; i>=0; i--){
        cin>>y;
        orden[i]=y-1;
    }


    y=0;
    while(y<n){
        floydWarshall();
        y++;
    }

    for(i=n-1; i>=0; i--){
        cout<<result[i];
        if(i>0){
            cout<<" ";
        }
    }
    cout<<endl;
}