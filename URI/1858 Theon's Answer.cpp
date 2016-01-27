#include <iostream>
using namespace std;
 
int main() {
    int n, menor, pos, i, a;
    cin>>n;
    menor=110; pos=i=1;
     
     
    while(i<=n){
        cin>>a;
        if(a<menor){
            menor=a;
            pos=i;
        }
        i++;
    }
     
    cout<<pos<<endl;
    return 0;
}