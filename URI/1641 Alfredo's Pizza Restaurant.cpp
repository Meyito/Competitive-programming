#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    int r,i;
    double l,w;
    cin>>r;
     
    i=1;
    while(r!=0){
        cin>>l>>w;
        l/=2;
        w/=2;
        if(l * l + w * w <= r * r){
            cout<<"Pizza "<<i<<" fits on the table.\n";
        }else{
            cout<<"Pizza "<<i<<" does not fit on the table.\n";
        }
        i++;
        cin>>r;
    }
     
}