#include <iostream>
#define endl "\n"
 
using namespace std;
int main(){
    int a,b;
    float c,total;
    cin>>a>>b>>c;
    total=c*b;
    cin>>a>>b>>c;
    total+=(c*b);
    a=a+(b*0.15);
    printf ("VALOR A PAGAR: R$ %.2f\n", total);
}