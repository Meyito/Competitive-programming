#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, bool> coords;
map<pair<int,int>, bool> visit;
bool flag;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int lab[5][5];

bool dfs(int y, int x){
	if(y==4 && x==4)	return true;
	
	coords[make_pair(y,x)]=true;
	
	int xx, yy, i;
	
	for(i=0; i<4; i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=0 && xx<5 && yy>=0 && yy<5 && lab[yy][xx]==0 && !coords[make_pair(yy,xx)]){
			if(dfs(yy,xx)){
				return true;	
			}
		}
	}
	
	return false;
}

int main() {
	int n, x, i, j;
	cin>>n;
	string s;
	
	while(n>0){
		flag=false;
		coords.clear();
		
		for(i=0; i<5; i++){
			for(j=0; j<5; j++){
				cin>>lab[i][j];
			}
		}
		
		flag=false;
		
		if(lab[0][0]==0){
			flag=dfs(0,0);
		}
		
		if(flag){
			cout<<"COPS\n";
		}else{
			cout<<"ROBBERS\n";
		}
		n--;
	}
	return 0;
}