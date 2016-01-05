#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string w;
    cin>>n;

    while(n>0){
        cin>>w;
        if(w.size()<=10){
            cout<<w<<"\n";
        }else{
            cout<<w[0]<<w.size()-2<<w[w.size()-1]<<"\n";
        }
        n--;
    }
}