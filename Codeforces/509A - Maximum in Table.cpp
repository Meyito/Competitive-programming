#include<iostream>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, i, j;
    cin>>n;
    int matriz[n][n];

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==0 || j==0){
                matriz[i][j]=1;
            }else{
                matriz[i][j]=matriz[i-1][j]+ matriz[i][j-1];
            }
        }
    }

    cout<<matriz[n-1][n-1]<<endl;
}