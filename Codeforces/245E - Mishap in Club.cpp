#include <iostream>
using namespace std;

int main() {
    int minus, plus, rta;
    rta=0;
    minus=0;
    plus=0;
    char x;
    while(cin>>x){
        if(x=='+'){
            if(minus==0){
                rta++;
            }else{
                minus--;
            }
            plus++;
        }else{
            if(plus==0){
                rta++;
            }else{
                plus--;
            }
            minus++;
        }
    }
    cout<<rta<<"\n";
    return 0;
}