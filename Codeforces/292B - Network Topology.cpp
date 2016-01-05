#include <bits/stdc++.h>
#define endl "\n"

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int v,e,i, x;
    cin>>v>>e;
    int grado[v+1];
    memset(grado, 0, (v+1)*sizeof(int));
    while(e>0){
        cin>>x;
        grado[x]++;
        cin>>x;
        grado[x]++;
        e--;
    }

    int uno=0, dos=0, nMenos=0;
    for(i=1; i<=v; i++){
        x=grado[i];
        if(x==1){
            uno++;
        }else if(x==2){
            dos++;
        }else if(x==(v-1)){
            nMenos++;
        }
    }

    if(dos==v){
        cout<<"ring topology"<<endl;
    }else if(dos==(v-2) && uno==2){
        cout<<"bus topology"<<endl;
    }else if(nMenos==1 && uno==(v-1)){
        cout<<"star topology"<<endl;
    }else{
        cout<<"unknown topology"<<endl;
    }

}