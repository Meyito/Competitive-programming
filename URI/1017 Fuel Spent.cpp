#include <iostream>
#include <stdio.h>
#define endl "\n"
 
using namespace std;
 
int main(){
    int t,v;
    cin>>t>>v;
    float x=t*v;
    x=x/12;
    printf("%.3f\n", x);
}