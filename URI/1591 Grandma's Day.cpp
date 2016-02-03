#include <bits/stdc++.h>
using namespace std;

char puzzle[55][55];
int l,c, cant;
int dx[]={1,0};
int dy[]={0,1};


void find(string w, int y, int x, int pos, int dir){
	if(pos>=w.size()){
		return;
	}
	
	if(y>=0 && y<l && x>=0 & x<c && puzzle[y][x]==w[pos]){
		if(pos==w.size()-1){
			cant++;
			return;
		}else{
			find(w, y+dy[dir], x+dx[dir], pos+1, dir);
		}
	}
}

int main() {
	int tc, i, j, p, f, s;
	map<char, vector<pair<int, int> > > abc;
	string w;
	cin>>tc;
	while(tc>0){
		cin>>l>>c;
		abc.clear();
		for(i=0; i<l; i++){
			for(j=0; j<c; j++){
				cin>>puzzle[i][j];
				abc[puzzle[i][j]].push_back(make_pair(i,j));
			}
		}
		cin>>p;
		while(p>0){
			cin>>w;
			cant=0;
			
			for(j=0; j<abc[w[0]].size(); j++){
				f=abc[w[0]][j].first;
				s=abc[w[0]][j].second;
				if(w.size()>1){
					for(i=0; i<2; i++){
						find(w, f+dy[i], s+dx[i], 1, i);
					}
				}else{
					cant++;
				}
			}
			
			cout<<cant<<"\n";
			p--;
		}
		tc--;
	}
	return 0;
}