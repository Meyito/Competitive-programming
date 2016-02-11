#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    double a,b,c, raiz, rta;
    
    while(cin>>a>>b>>c){
        if(a==0 || (b*b)<(4*a*c)){
            printf("Impossivel calcular\n");
        }else{
            raiz=(b*b)-(4*a*c);
            raiz=sqrt(raiz);
            
            rta=-b+raiz;
            rta/=(2*a);
            printf("R1 = %.5lf\n", rta);
            
            rta=-b-raiz;
            rta/=(2*a);
            printf("R2 = %.5lf\n", rta);
        }
    }
    return 0;
}