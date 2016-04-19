/*
	Help Ashu
	https://www.hackerearth.com/problem/algorithm/help-ashu-1/
*/

#include <bits/stdc++.h>

using namespace std;

struct seg_tree{ 
	vector< vector<int> > st; //pares, impares
	vector<int> data;
	int N;

	seg_tree(int _N, vector<int> &_data){
		data = _data;
		N = _N;
		st.resize(4*N);
		init(1, 1, N); //nodo, inicio, fin
	}

	int left(int L){
		return L << 1; 
	}

	int right(int R){
		return R << 1 | 1;
	}

	void init(int node, int L, int R){
		if(L==R){
			if(data[L]%2==0){
				st[node].push_back(1);
				st[node].push_back(0);
			}else{
				st[node].push_back(0);
				st[node].push_back(1);
			}
		}else{
			int mid;
			vector<int> p1, p2;
			mid = (L+R)/2;
			init(left(node), L, mid);
			init(right(node), mid+1, R);
			p1 = st[left(node)];
			p2 = st[right(node)];
			
			st[node].push_back(p1[0]+ p2[0]);
			st[node].push_back(p1[1]+ p2[1]);
		}
	}

	int query(int node, int L, int R, int i, int j, int type){
		if(i > R || j < L){
			return -1;
		}

		if(L >= i && R <= j){
			return (type==1) ? st[node][0] : st[node][1];
		}
	
		int mid, p1, p2;

		mid = (L+R) >> 1;
		p1=query(left(node), L, mid, i, j, type);
		p2=query(right(node), mid+1, R, i, j, type);

		if(p1 == -1)	return p2;
		if(p2 == -1)	return p1;

		return p1+p2;

	}

	int query(int i, int j, int type){
		return query(1, 1, N, i, j, type);
	}

	vector<int> update(int node, int L, int R, int i, int value){
		if(i < L || i > R){
			return st[node]; //out of range
		}

		if(L == R){
			data[i] = value;
			if(value%2==0){
				st[node][0]=1;
				st[node][1]=0;
			}else{
				st[node][0]=0;
				st[node][1]=1;
			}
			return st[node];
		}else{
			int mid = (L+R) >> 1;
			vector<int> p1 = update(left(node), L, mid, i, value);
			vector<int> p2 = update(right(node), mid+1, R, i, value);

			st[node][0] = p1[0]+p2[0];
			st[node][1] = p1[1]+p2[1];
			
			return st[node];
		}
	}

	void update(int i, int value){
		update(1, 1, N, i, value);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q, i, x, t;
	vector<int> a;
	
	cin>>n;
	a.push_back(0);
	
	for(i=1; i<=n; i++){
		cin>>x;
		a.push_back(x);
	}
	
	seg_tree tree(n+1, a);
	
	cin>>q;
	while(q>0){
		cin>>t>>i>>x;
		if(t==0){
			tree.update(i, x);
		}else{
			cout<<tree.query(i, x, t)<<"\n";
		}
		q--;
	}
	
	
	
	
	return 0;
}