#include <bits/stdc++.h>
#define endl "\n"

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    string s;
    int n;
    cin>>s;

    n=26*(s.length()+1);
    n-=s.length();
    cout<<n<<endl;
}