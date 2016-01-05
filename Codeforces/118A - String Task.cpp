#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    char x;
    cin>>s;
    
    for(int i=0; i<s.size(); i++){
        x=s[i];
        if(x!='a' && x!= 'e'  && x!= 'Y'  && x!= 'y' && x!= 'i' && x!= 'o' && x!= 'u' && x!= 'A' && x!= 'E' && x!= 'I' && x!= 'O' && x!= 'U'){
            cout<<".";
            if(x>65 && x<=90){
                x+=32;
            }
            cout<<x;
        }
    }
    cout<<"\n";
    return 0;
}