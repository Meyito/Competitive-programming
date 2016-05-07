#include <bits/stdc++.h>

using namespace std;

const int K = 50010;
const int N = 110;
bool dp[N][K];
int s[N];
int cant, sum;

void init(){
	int i, j;
	for(i = 0; i <= cant; i++){
		for(j = 0; j <= sum; j++){
			if(j == 0){
				dp[i][j] = true;
			}else{
				dp[i][j] = false;
			}
		}
	}
}

void possible(){
	int n, k;
	
	for(n=1; n<=cant; n++){
		for(k = 1; k <= sum; k++){
			if(s[n] > k){
				dp[n][k] = dp[n-1][k];
			}else{
				dp[n][k] = dp[n-1][k] || dp[n-1][k-s[n]];
			}	
		}
	}
}

int resolve(){
	int i, aux;
	int menor = sum;
	
	for(i = 0; i <= sum ; i++){
		
		if(dp[cant][i]){
			aux = abs ((sum - i) - i);
		
			if(aux < menor){
				menor = aux;
			}
			
			if(aux > menor){
				break;
			}
		}
	}
	
	return menor;
}

int main(){
	int tc,i;
	cin>>tc;
	
	while(tc > 0){
		cin>>cant;
		sum = 0;
		s[0] = 0;
		for(i = 1; i <= cant; i++){
			cin>>s[i];
			sum += s[i];
		}
		init();
		
		possible();
		cout<<resolve()<<"\n";
		tc--;
	}
}