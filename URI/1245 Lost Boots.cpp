#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, tam, rta;
    char x;
    map<int,int> d;
    map<int,int> e;
    
    while(cin>>n){
        d.clear();
        e.clear();
        rta=0;
        while(n>0){
            cin>>tam>>x;
            if(x=='D'){
                d[tam]++;
            }else{
                e[tam]++;
            }
            n--;
        }
        map<int,int>::iterator it;
        
        for(it=d.begin(); it!=d.end(); it++){
            rta+=min(d[it->first], e[it->first]);
        }
        
        cout<<rta<<"\n";
    }
    return 0;
}