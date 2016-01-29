#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    int n, l, c, pages, caracteres,i;
    string s;
    while(cin>>n){
        cin>>l>>c;
        pages=1; caracteres=0;
        i=0;
        while(i<n){
            if(caracteres!=0)   caracteres++;
            cin>>s;
            if(caracteres+s.size()>c){
                pages++;
                caracteres=s.size();
            }else{
                caracteres+=s.size();
            }
            i++;
        }
         
        //cout<<pages<<endl;
        cout<<ceil(((float)(pages)/l))<<endl;
    }
     
     
}