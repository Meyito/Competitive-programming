#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    int n, c, v, total;
     
    cin>>n;
    while(n!=0){
        total=0;
        while(n>0){
            cin>>c>>v;
            total+=(v/2);
            n--;
        }
        
        cout<<total/2<<"\n";
        cin>>n;
    }
     
     
}