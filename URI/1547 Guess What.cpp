#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int dif, ind, n, qt, s, x, i;
    cin>>n;
    while(n>0){
        cin>>qt>>s;
        i=1;
        ind=0;
        dif=-1;
        while(i<=qt){
            cin>>x;
            if(dif==-1 || abs(x-s)<dif){
                dif=abs(x-s);
                ind=i;
            }
            i++;
        }
        cout<<ind<<"\n";
        n--;
    }
    return 0;
}