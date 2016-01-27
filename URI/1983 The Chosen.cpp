#include <iostream>
using namespace std;
 
int main() {
    int n, i;
    long long reg, a;
    float maxN, b;
     
    cin>>n;
    maxN=0.0;
     
    while(n>0){
        cin>>a>>b;
         
        if(b>maxN){
            maxN=b;
            reg=a;
        }
        n--;
    }
     
    if(maxN>=8){
        cout<<reg<<"\n";
    }else{
        cout<<"Minimum note not reached\n";
    }
 
    return 0;
}