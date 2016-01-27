#include <iostream>
#include <stdio.h>
#include <math.h>
#define endl "\n"
 
using namespace std;
 
int main(){
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    double rta=sqrt((pow(x2-x1, 2))+(pow(y2-y1, 2)));
    printf("%.4f\n", rta);
     
}