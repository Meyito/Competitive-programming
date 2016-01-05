#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define endl "\n"
     
using namespace std;
     
int main(){
   long long a,b, s, pasos;
   cin>>a>>b>>s;
   pasos=abs(a)+abs(b);
   if(s<pasos){
    cout<<"No"<<endl;
  }else{
    pasos-=s;
    if(pasos%2==0){
    cout<<"Yes"<<endl;
   }else{
    cout<<"No"<<endl;
   }
  }
     
 }