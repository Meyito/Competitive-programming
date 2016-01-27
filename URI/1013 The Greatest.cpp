#include <iostream>
#include <stdlib.h>
#define endl "\n"
 
using namespace std;
 
int main(){
    int a,b,c, mayorAB, mayorC;
    cin>>a>>b>>c;
     
    mayorAB=(a+b+abs(a-b))/2;
     
    mayorC=(mayorAB+c+abs(mayorAB-c))/2;
     
    cout<<mayorC<<" eh o maior"<<endl;
}