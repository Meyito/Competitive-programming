#include <bits/stdc++.h>
#define endl "\n"

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int n,i,aux;
    cin>>n;
    int amigos[n+1];
    
    i=1;
    while(i<=n){
        cin>>aux;
        amigos[aux]=i;
        i++;
    }
    
    while(n>1){
        cin>>aux;
        cout<<amigos[aux]<<" ";
        n--;
    }
    cin>>aux;
    cout<<amigos[aux]<<endl;
}