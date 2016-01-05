#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,i,j,auxj;
    
    cin>>n>>m;
    
    int elements[n+1], increase[n+1], decrease[n+1];
    increase[0]=decrease[0]=elements[0]=0;
    
    for(i=1; i<=n; i++){
        cin>>elements[i];
        
        if(elements[i-1]<elements[i]){
            increase[i]=increase[i-1]+1;
            decrease[i]=1;
        }else if(elements[i-1]>elements[i]){
            decrease[i]=decrease[i-1]+1;
            increase[i]=1;
        }else{
            increase[i]=increase[i-1]+1;
            decrease[i]=decrease[i-1]+1;
        }
    }
    
    while(m>0){
        cin>>i>>j;
        
        if(increase[j]>=(j-i+1) || decrease[j]>=(j-i+1)){
            cout<<"Yes\n";
        }else{
            auxj=j-decrease[j];
            
            if(increase[auxj]>=(auxj-i+1)){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
        
        m--;
    }
    return 0;
}