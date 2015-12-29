/*
 * Problem: 628 - Passwords                                 
 * Url: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=569                           
*/

#include <bits/stdc++.h>

using namespace std;

string dictionary[110];
int n;

void make(string rule, int pos, string ans){
	if(pos==rule.size()){
		cout<<ans<<endl;
		return;
	}
	
	int i;
	
	if(rule[pos]=='#'){
		for(i=0; i<n; i++){
			make(rule, pos+1, ans+dictionary[i]);
		}
	}else{
		for(i=0; i<10; i++){
			make(rule, pos+1, ans+(char)(i+48));
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int i, m;
	string rule, ans;
	while(cin>>n){
		for(i=0; i<n; i++){
			cin>>dictionary[i];
		}
		cin>>m;
		
		cout<<"--\n";
		
		while(m>0){
			cin>>rule;
			ans="";
			make(rule, 0, ans);
			m--;
		}
	}
	return 0;
}
