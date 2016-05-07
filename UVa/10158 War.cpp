#include <bits/stdc++.h>

using namespace std;

int n;
int friends[20010]; 
int r[20010]; 

void init(){
  for(int i = 0; i < (n*2)+10 ; i++){
    friends[i] = i;
    r[i] = 0;
  }
}

int find (int i){
  if( friends[i] != i ){
    friends[i] = find( friends[i] );
  }
  return friends[i];
}

bool areFriends(int x, int y){
	if(find(x) == find(y) || find(x+n) == find(y+n)){
		return true;
	}
	return false;
}

bool areEnemies(int x, int y){
	if ( find(x) == find(y+n) || find(y) == find(x+n)){
		return true;
	}
	
	return false;
}

void make_union(int x, int y){
  
  int xroot = find(x);
  int yroot = find(y);
  
  if(xroot != yroot){
  	if (r[xroot] < r[yroot])
  		friends[xroot] = yroot;
  	else if (r[xroot] > r[yroot])
  		friends[yroot] = xroot;
	else{
	  friends[yroot] = xroot;
	  r[xroot]++;
	}
  }
  
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int c, x, y;
	
	cin>>n;
	init();
	
	cin>>c>>x>>y;
	
	while(c!=0){
		
		if(c == 1){
			if( areEnemies(x, y) ){
				cout<<-1<<"\n";
			}else{
				make_union(x, y);
				make_union(x+n, y+n);
			}
		}else if(c == 2){
			if( areFriends(x, y) ){
				cout<< -1 << "\n";
			}else{
				make_union(x, y+n);
				make_union(y, x+n);
			}
		}else if(c == 3){
			cout<< areFriends(x, y) << "\n";
		}else{
			cout<< areEnemies(x, y) << "\n";
		}
		
		cin>>c>>x>>y;	
	}
	
	return 0;
}