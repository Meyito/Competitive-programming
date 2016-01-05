#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    int n,m,a,i, cont;
    cin>>n>>m;
    vector<int> tam;
    while(n>0){
        cin>>a;
        tam.push_back(a);
        n--;
    }

    sort(tam.begin(), tam.end());

    cont=0;
    i=tam.size()-1;
    while(m>0){
            m-=tam[i];
            i--;
            cont++;
    }

    cout<<cont<<endl;
    return 0;
}