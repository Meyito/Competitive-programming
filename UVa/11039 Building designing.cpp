#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc, n, x, cont, ant;
	vector<pair<int, int> > f;
	cin>>tc;
	
	while(tc>0){
		cin>>n;
		f.clear();
		cont=1;
		while(n>0){
			cin>>x;
			if(x<0){
				f.push_back(make_pair(abs(x), -1));
			}else{
				f.push_back(make_pair(abs(x), 1));
			}
			n--;
		}
		
		sort(f.begin(), f.end() );
			
		vector<pair<int, int> >::reverse_iterator it;
		it=f.rbegin();
		ant=it->second;
		it++;
		while(it!=f.rend()){
			if(it->second!=ant){
				cont++;
				ant=it->second;
			}
			it++;
		}
		cout<<cont<<"\n";
		tc--;
	}
	return 0;
}