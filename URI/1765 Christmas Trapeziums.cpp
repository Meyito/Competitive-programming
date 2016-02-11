#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc,q, i;
    double a, b, area;
    
    cin>>tc;
    
    while(tc!=0){
        
        i=1;
        while(i<=tc){
            cin>>q>>a>>b;
            area=(a+b)*5;
            area/=2;
            area*=q;
            printf("Size #%d:\n",i);
            printf("Ice Cream Used: %.2lf cm2\n", area);
            i++;
        }
        printf("\n");
        cin>>tc;
    }
    
    return 0;
}