#include <iostream>
#include <math.h>
#include <stdio.h>
#define endl "\n"
 
using namespace std;
 
int main(){
    double r;
    cin>>r;
    r=pow(r, 3.0);
    r=(4.0/3)*3.14159*r;
    printf("VOLUME = %.3f", r);
    cout<<endl;
}