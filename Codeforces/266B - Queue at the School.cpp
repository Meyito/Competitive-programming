#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    int n, t, i,j;
    cin>>n>>t;
    char cola[n];
    for(i=0; i<n; i++){
        cin>>cola[i];
    }
    j=0;
    int swap;
    char actual, siguiente;
    while(j<t){
        swap=0;
        if(sizeof(cola)>1){
            for(i=0; i<n-1; i++){
                actual=cola[i];
                siguiente=cola[i+1];
                if(actual=='B' && siguiente=='G'){
                    swap=1;
                    cola[i]='G';
                    cola[i+1]='B';
                    i++;
                }
            }
        }else{
            break;
        }
      
        if(swap==0){
            break;
        }
        j++;
    }

    for(i=0; i<n; i++){
        cout<<cola[i];
    }
    cout<<endl;

}