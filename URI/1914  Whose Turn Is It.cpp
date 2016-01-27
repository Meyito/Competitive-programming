#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc, i;
    long long n, m;
    string nom, choice;
    map<int, string> names;
 
    while(cin>>tc){
        while(tc>0){
             
            for(i=0; i<2; i++){
                cin>>nom>>choice;
                 
                if(choice=="PAR"){
                    names[0]=nom;
                }else{
                    names[1]=nom;
                }
            }
            cin>>n>>m;
            n=(n+m)%2;
             
            cout<<names[n]<<endl;
             
            tc--;
        }
     
    }
    return 0;
}