#include <bits/stdc++.h>

using namespace std;

const int C = 7490;
const int N = 6;
int dp[C][N];
int d[] = {0, 1, 5, 10, 25, 50};
int c;

int knapsack(){
	int i, j;
	
	for(i = 0; i<=C; i++){
		for(j=0; j<N; j++){
			if(i == 0){
				dp[i][j] = 1;
			}else if(j == 0 && i>0){
				dp[i][j] = 0;
			}else if(d[j] > i){
				dp[i][j] = dp[i][j-1];
			}else{
				dp[i][j] = dp[i][j-1] + dp[i-d[j]][j];
			}
		}
	}
}

int main(){
	
	knapsack();
	
	while(cin>>c){
		cout<<dp[c][5]<<"\n";
	}
}