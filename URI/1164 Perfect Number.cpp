#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc, n, i, aux;
    bool flag;
 
    while(cin>>tc){
        while(tc>0){
            cin>>n;
         
            flag = true;
            aux=1;
            for(i=2; i<n; i++){
                if(n%i==0){
                    aux+=i;
                    if(aux>n)    break;
                }
            }
         
            if(aux!=n || n==1)  flag=false;
            if(flag){
                cout<<n<<" eh perfeito\n";
            }else{
                cout<<n<<" nao eh perfeito\n";
            }
            tc--;
        }
     
    }
    return 0;
}