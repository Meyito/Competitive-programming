#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {
	int n, t, i;
	cin>>n>>t;
	int cells[n+1];
	bool flag=false;
	
	for(i=1; i<=n; i++){
		cin>>cells[i];
	}
	
	i=1;
	while(i<=n){
		if(i==t){
			flag=true;
			break;
		}else if(i>t){
			break;
		}
		i+=cells[i];
	}
	
	if(flag){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}