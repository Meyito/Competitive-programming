#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k,rta,x;
    map<int,int> cant;
    cin>>n>>k;
    while(n!=0 && k!=0){
        rta=0;
        cant.clear();
        while(n>0){
            cin>>x;
            cant[x]++;
            if(cant[x]==k){
                rta++;
            }
            n--;
        }
        cout<<rta<<"\n";
        cin>>n>>k;
    }
    return 0;
}