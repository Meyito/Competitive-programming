#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long x, y, rta;
    y=2015;
    int n;
    cin>>n;
    while(n>0){
        cin>>x;
        if(x<y){
            cout<<y-x<<" D.C.\n";
        }else{
            cout<<x-y+1<<" A.C.\n";
        }
        n--;
    }
     
    return 0;
}