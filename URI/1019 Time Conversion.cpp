#include <iostream>
  
using namespace std;
  
int main() {
  
    int minutos;
    cin>>minutos;
    if(minutos>3600){
        cout<<(minutos/3600)<<":";
        minutos=minutos-(3600*(minutos/3600));
    }else{
        cout<<"0:";
    }
     
    if(minutos>60){
        cout<<(minutos/60)<<":";
        minutos=minutos-(60*(minutos/60));
    }else{
        cout<<"0:";
    }
     
    cout<<minutos<<endl;
     
    return 0;
}