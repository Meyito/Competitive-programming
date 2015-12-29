/*
 * Problem: 11450 - Wedding shopping                              
 * Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2445
*/

#include <bits/stdc++.h>

using namespace std;

int m, c, garments[25][25];
int memo[205][25];

int shop(int money, int actualGarment){  //Dinero disponible/prenda analizada

	if(money<0)
		return -10000000;

	if(actualGarment==c)
		return m-money;

	if(memo[money][actualGarment] != -1)
		return memo[money][actualGarment];   //CRUCIAL DP

	int ans=-1;

	for(int model=1; model<=garments[actualGarment][0]; model++){
		ans=max(ans, shop(money-garments[actualGarment][model], actualGarment+1));
	}

	memo[money][actualGarment]=ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc, i , j, k, rta;
	cin>>tc;

	while(tc>0){
		cin>>m>>c;

		for(i=0; i<c; i++){
			cin>>k;
			garments[i][0]=k;

			for(j=1; j<=k; j++){
				cin>>garments[i][j];
			}

		}

		memset(memo, -1, sizeof memo);

		rta=shop(m, 0);

		if(rta<0){
			cout<<"no solution\n";
		}else{
			cout<<rta<<"\n";
		}

		tc--;
	}

	return 0;
}

