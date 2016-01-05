#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    long long a,b,aux,cont;
    cin>>a>>b;
    cont=0;
    while(a!=b){
        cont+= (a/b);
        if(a%b!=0){
            aux=b;
            b=a%b;
            a=aux;
        }else{
            break;
        }
    }
    cout<<cont<<endl;
    return 0;
}