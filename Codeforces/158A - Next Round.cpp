#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, i, rta;
    cin>>n>>k;
    int places[n+1];
    
    for(i=1; i<=n; i++){
        cin>>places[i];
    }
    
    rta=k;
    if(places[k]<=0){
        rta=0;
        i=1;
        while(i<k && places[i]!=0){
            rta++;
            i++;
        }
    }else{
        i=k+1;
        while(i<=n && places[i]>=places[k]){
            i++;
            rta++;
        }
    }
    
    cout<<rta<<"\n";
}