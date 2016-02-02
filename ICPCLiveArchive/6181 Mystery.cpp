#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc, i, n, pos, aux;
    string s;
    char a;
    
    cin>>tc;
    
    while(tc>0){
        cin>>i;
        getline(cin, s);    
        getline(cin, s);
        cin>>n;
        
        cout<<i<<" ";
    
        pos=0;
        while(n>0){
            cin>>aux;
            
            pos=pos+aux;
            
            if(pos>0 && pos>=s.size()){
                pos%=s.size();
            }

            if(pos<0){
                pos=s.size()+pos;
            }
            cout<<s[pos];

            n--;
        }
        
        cout<<"\n";
        tc--;
    }
    
    return 0;
}