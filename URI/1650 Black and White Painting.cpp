#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,m,c, y, x, h, xx;
    long long rta;
    cin>>n;
    while(n!=0){
        cin>>m>>c;
        rta=0;
         
        if(c==1){
            x=1+((m-8)/2);
            xx=0;
            if(m>8){
                xx=1+((m-9)/2);
            }
             
            y=1+(n-8);
             
            h=y/2;
            if(y%2==0){
                rta=(x*h)+((xx)*h);
            }else{
                rta=(x*(h+1))+((xx)*h);
            }
        }else{
            x=0;
            xx=1+((m-8)/2);
            if(m>8){
                x=1+((m-9)/2);
            }
             
            y=1+(n-8);
             
            h=y/2;
            if(y%2==0){
                rta=(x*h)+((xx)*h);
            }else{
                rta=(x*(h+1))+((xx)*h);
            }   
        }
         
        cout<<rta<<"\n";
        cin>>n;
    }
     
    return 0;
}