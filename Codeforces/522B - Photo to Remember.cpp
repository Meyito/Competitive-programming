#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, W, H, i, iH, cont, aux;
    cin>>n;
    int w[n];
    vector<int> h;

    i=0;
    W=0;
    H=0;
    iH=0;
    cont=0;
    while(i<n){
        cin>>w[i];
        W+=w[i];
        cin>>aux;
        h.push_back(aux);
        if(h[i]>H){
            H=h[i];
            iH=i;
            cont=1;
        }else if(h[i]==H){
            cont++;
        }
        i++;
    }

    sort(h.begin(), h.end());
    
    i=0;
    while(i<n){
        if(i>0 && i<n){
            cout<<" ";
        }
        if(cont==1 && i==iH){
            cout<<(W-w[i])*h[n-2];
        }else{
            cout<<(W-w[i])*H;
        }

        i++;
    }
    
    cout<<endl;
}