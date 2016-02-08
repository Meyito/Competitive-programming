#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,b, i, x, rta;
    cin>>n>>b;
    vector<int> f;
    vector<int> s;
 
    for(i=0; i<n; i++){
        cin>>x;
        f.push_back(x);
    }
    for(i=0; i<n; i++){
        cin>>x;
        s.push_back(x);
    }
 
    sort(f.begin(), f.end());
    sort(s.begin(), s.end());
 
    i=0; x=n-1;
    rta=0;
    
    while(i<n && x>=0){
        if(f[i]+s[x]>=b){
            rta++;
            x--;
        }
        i++;
    }
 
    cout<<1<<" "<<rta<<"\n";
    return 0;
}