#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    double x;

    int n, n1,xx;
    while(cin>>x){
        xx=x;
        n1=(x*100);
        
        printf("NOTAS:\n");
        printf("%d nota(s) de R$ %.2lf\n", xx/100, (double)100);
        n=xx%100;
        printf("%d nota(s) de R$ %.2lf\n", n/50, (double)50);
        n%=50;
        printf("%d nota(s) de R$ %.2lf\n", n/20, (double)20);
        n%=20;
        printf("%d nota(s) de R$ %.2lf\n", n/10, (double)10);
        n%=10;
        printf("%d nota(s) de R$ %.2lf\n", n/5, (double)5);
        n%=5;
        printf("%d nota(s) de R$ %.2lf\n", n/2, (double)2);
        n%=2;
        printf("MOEDAS:\n");
        printf("%d moeda(s) de R$ %.2lf\n", n/1, (double)1);
        n1%=100;
        printf("%d moeda(s) de R$ %.2lf\n", n1/50, 0.50);
        n1%=50;
        printf("%d moeda(s) de R$ %.2lf\n", n1/25, 0.25);
        n1%=25;
        printf("%d moeda(s) de R$ %.2lf\n", n1/10, 0.10);
        n1%=10;
        printf("%d moeda(s) de R$ %.2lf\n", n1/5, 0.05);
        n1%=5;
        printf("%d moeda(s) de R$ %.2lf\n", n1/1, 0.01);
    }
    
    return 0;
}