#include <iostream>
#include <math.h>
#define endl "\n"
 
using namespace std;
 
int nota;
 
void calcular(float valor){
    int rta=0;
    if(nota>=valor){
        rta=nota/valor;
        nota-=(valor*rta);
    }
    cout<<rta<<" nota(s) de R$ "<<valor<<",00"<<endl;
}
 
int main(){
    cin>>nota;
    cout<<nota<<endl;
    calcular(100.00);
    calcular(50.00);
    calcular(20.00);
    calcular(10.00);
    calcular(5.00);
    calcular(2.00);
    calcular(1.00);
}