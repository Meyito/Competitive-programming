#include <bits/stdc++.h>
#define endl "\n";

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int m,n,i,j,t;

    cin>>m>>n;

    int paints[m][n];

    for(i=0; i<m; i++){
        if(i>0){
            cout<<" ";
        }
        for(j=0; j<n; j++){
            cin>>paints[i][j];
            if(i>0){
                if(j>0){
                    paints[i][j]+=max(paints[i][j-1], paints[i-1][j]);
                }else{
                    paints[i][j]+=paints[i-1][j];
                }
            }else if(j>0){
                paints[i][j]+=paints[i][j-1];
            }
        }
        cout<<paints[i][n-1];
    }

    cout<<endl;
    
    return 0;
}