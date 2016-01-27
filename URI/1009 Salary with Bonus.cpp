#include <iostream>
 
using namespace std;
int main(){
    string s;
    double a,b,total;
    cin>>s>>a>>b;
    b*=0.15;
    b+=a;
    printf ("TOTAL = R$ %.2f\n", b);
}