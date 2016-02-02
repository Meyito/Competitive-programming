#include <bits/stdc++.h>

using namespace std;

int hailstone(int n){
    if(n==1){
        return 1;
    }
    
    if(n%2==0){
        return max(n, hailstone(n/2));
    }
    return max(n, hailstone( (n*3)+1 ) );
}

int main() {
    int i,p,n;
    cin>>p;
    
    while(p>0){
        cin>>i>>n;
        n=hailstone(n);
        cout<<i<<" "<<n<<"\n";
        p--;
    }
    return 0;
}