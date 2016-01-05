#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int rta;

char plate[100][10];

void dfs(int x, int y, int n, int m, int nivel){

    int dx[]={0,1,-1,0,0,0};
    int dy[]={n,0,0,-1,1,-n};
    
    rta++;
    plate[y][x]='s';
    int xx,yy, i, nn;

    for(i=0; i<6; i++){
        xx=x+dx[i];
        yy=y+dy[i];
        
        nn=nivel;
        
        if(i==0){
            nn=nivel+1;
        }else if(i==5){
            nn=nivel-1;
        }

        if(xx>=0 && xx<m && yy>=(nn-1)*n && yy<nn*n && plate[yy][xx]=='.'){
            dfs(xx, yy, n, m, nn);
        }
    }
}

int main(){
    int k,n,m, i, j, l, x,y;
    string s;
    cin>>k>>n>>m;
    
    for(i=0; i<k*n; i++){
            for(l=0; l<m; l++){
                cin>>plate[i][l];
            }
    }

    cin>>x>>y;
 
    rta=0;
    dfs(y-1, x-1, n, m, 1);

    cout<<rta<<endl;
}