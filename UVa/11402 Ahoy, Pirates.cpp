#include <bits/stdc++.h>

using namespace std;

struct seg_tree{
	vector<int> st, lazy;
	int N;
	
	seg_tree(int n){
		st.resize(n*4+10);
		lazy.resize(n*4+10);
	}
	
	void init(vector<int> &pirates, int node, int L, int R){
		lazy[node]=0; //clearing
		
		if(L==R){
			st[node]=pirates[L];
			return;
		}
		
		int p1, p2, mid;
		mid = (L + R) / 2;
		p1 = node * 2;
		p2 = p1 + 1;
		
		init(pirates, p1, L, mid);
		init(pirates, p2, mid+1, R);
		
		st[node] = st[p1] + st [p2];
	}
	
	void propagate(int node, int L, int R){
		if(lazy[node]==1){
			
			st[node] = 0;
			if(L != R){
				lazy[node*2] = lazy[node*2 +1] = 1;
			}
			
		}else if(lazy[node]==2){
			
			st[node] = (R - L + 1);
			if(L != R){
				lazy[node*2] = lazy[node*2 +1] = 2;
			}
			
		}else if(lazy[node]==3){
			
			st[node] = (R - L + 1) - st[node];
			if(R != L){
				updateLazy(node*2);
				updateLazy(node*2 +1);
			}
		}
		
		lazy[node]=0;
	}
	
	void updateUp(int node, int L, int R, int i, int j){
		// cout<<node<<" "<<L<<" "<<R<<" "<<i<<" "<<j<<endl;
		propagate(node, L, R);
		
		if(i > R || j < L){
			return;
		}
		
		if( L >= i && R <= j ){
			st[node] = (R - L + 1);
			
			if(R != L){
				lazy[node*2] = lazy[node*2 +1] = 2;
			}
			
			return;
		}
		
		int p1, p2, mid;
		mid = (L + R) / 2;
		p1 = node * 2;
		p2 = p1 + 1;
		
		updateUp(p1, L, mid, i, j);
		updateUp(p2, mid+1, R, i, j);
		
		st[node] = st[p1] + st [p2];
	}
	
	void updateDown(int node, int L, int R, int i, int j){
		propagate(node, L, R);
		
		if(i > R || j < L){
			return;
		}
		
		if( L >= i && R <= j){
			st[node] = 0;
			
			if(R != L){
				lazy[node*2] = lazy[node*2 +1] = 1;
			}
			return;
		}
		
		int p1, p2, mid;
		mid = (L + R) / 2;
		p1 = node * 2;
		p2 = p1 + 1;
		
		updateDown(p1, L, mid, i, j);
		updateDown(p2, mid+1, R, i, j);
		
		st[node] = st[p1] + st [p2];
	}
	
	void updateLazy(int node){
		if(lazy[node]==0){
			lazy[node]=3;
		}else if(lazy[node]==3){
			lazy[node]=0;
		}else if(lazy[node]==2){
			lazy[node]=1;
		}else{
			lazy[node]=2;
		}
	}
	
	void swap(int node, int L, int R, int i, int j){
		//cout<<node<<" "<<L<<" "<<R<<" "<<i<<" "<<j<<endl;
		propagate(node, L, R);
		
		if(i > R || j < L){
			return;
		}
		
		if( L >= i && R <= j){
			st[node] = (R - L + 1) - st[node];
			
			if(R != L){
				updateLazy(node*2);
				updateLazy(node*2 +1);
			}
			return;
		}
		
		int p1, p2, mid;
		mid = (L + R) / 2;
		p1 = node * 2;
		p2 = p1 + 1;
		
		swap(p1, L, mid, i, j);
		swap(p2, mid+1, R, i, j);
		
		st[node] = st[p1] + st [p2];
	}
	
	int query(int node, int L, int R, int i, int j){
		propagate(node, L, R);
		
		if( i > R || j < L) {
			return 0;
		}
		
		if( L >= i && R <= j){
			return st[node];
		}
		
		int p1, p2, mid;
		mid = (L + R) / 2;
		p1 = node * 2;
		p2 = p1 + 1;
		
		return query(p1, L, mid, i, j) + query(p2, mid+1, R, i, j);
	}
	
	
};

seg_tree tree(1024000);

int main() {
 	ios_base::sync_with_stdio(false); cin.tie(NULL);
 	int TC, tc, n, m, t, i, j;
 	char c;
 	string s;
 	vector<int> pirates;
 	
 	cin>>TC;
 	tc=1;
 	
 	while(tc<=TC){
 		pirates.clear();
 		cin>>n;
 		
 		while(n>0){
 			cin>>m>>s;
 			while(m>0){
 				for(i=0; i<s.size(); i++){
 					pirates.push_back(s[i]-'0');
 				}
 				m--;
 			}
 			n--;
 		}
 		
 		tree.init(pirates, 1, 0, pirates.size()-1);
 		
 		cout<<"Case "<<tc<<":\n";
 		
 		cin>>m;
 		t=1;
 		while(m>0){
 			cin>>c>>i>>j;
 			
 			if(c=='F'){
 				tree.updateUp(1, 0, pirates.size()-1, i, j);
 			}else if(c=='E'){
 				tree.updateDown(1, 0, pirates.size()-1, i, j);
 			}else if(c=='I'){
 				tree.swap(1, 0, pirates.size()-1, i, j);
 			}else{
 				cout<<"Q"<<t<<": "<<tree.query(1, 0, pirates.size()-1, i, j)<<"\n";
 				t++;
 			}
 			m--;
 		}
 		
 		tc++;
 	}
 	
	return 0;
}