#include <iostream>
  
using namespace std;
  
int main() {
  
   int minutos;
    cin>>minutos;
    if(minutos>365){
        cout<<(minutos/365);
        minutos=minutos-(365*(minutos/365));
    }else{
        cout<<"0";
    }
    cout<<" ano(s)"<<endl;
     
    if(minutos>30){
        cout<<(minutos/30);
        minutos=minutos-(30*(minutos/30));
    }else{
        cout<<"0";
    }
    cout<<" mes(es)"<<endl;
     
    cout<<minutos<<" dia(s)"<<endl;
  
    return 0;
}