#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x, i;
	cin>>n;
	map<int,int> killers;
	
	while(n!=0){
		killers.clear();
		i=1;
		while(i<=n){
			cin>>x;
			killers[x]=i;
			i++;
		}
		
		map<int, int>::reverse_iterator it;
		it=killers.rbegin();
		it++;
		cout<<it->second<<"\n";
		
		cin>>n;
	}
	return 0;
}