#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    int tc, x;
    long double granos;
    unsigned long long rta;
    cin>>tc;
    while(tc>0){
        cin>>x;
        granos=pow(2,x);
        rta=granos/12000;
        cout<<rta<<" kg\n";
        tc--;
    }
     
     
}