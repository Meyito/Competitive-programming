#include<iostream>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long n,m,a,x,y;
    cin>>n>>m>>a;
    x=m/a;
    y=n/a;
    if(m%a!=0){
        x++;
    }
    if(n%a!=0){
        y++;
    }

    cout<<x*y<<endl;
}