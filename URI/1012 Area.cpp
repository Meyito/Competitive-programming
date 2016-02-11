#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    double a,b,c, rta;
    double p=3.14159;
    
    cin>>a>>b>>c;
    
    rta=(a*c)/2;
    printf("TRIANGULO: %.3lf\n", rta);
    
    rta=p*c*c;
    printf("CIRCULO: %.3lf\n", rta);
    
    rta=(a+b)*c;
    rta/=2;
    printf("TRAPEZIO: %.3lf\n", rta);
    
    rta=b*b;
    printf("QUADRADO: %.3lf\n",rta);
    
    rta=a*b;
    printf("RETANGULO: %.3lf\n", rta);
    
    return 0;
}