#include <bits/stdc++.h>
using namespace std;

int main() {
	double m[12][12];
	int i,j, k, w;
	int cont;
	double rta;
	string s;
	while(cin>>s){
		for(i=0; i<12; i++){
			for(j=0; j<12; j++){
				cin>>m[i][j];
			}
		}
		
		cont=rta=0;
		k=1;
		for(i=1; i<=10; i++){
			w=0;
			j=11;
			while(w<k){
				rta+=m[i][j];
				cont++;
				j--;
				w++;
			}
			if(i<5){
				k++;
			}if(i>5){
				k--;
			}
		}
		
		if(s=="S"){
			printf("%.1lf\n", rta);
		}else{
			printf("%.1lf\n", rta/cont);
		}
		
	}
	return 0;
}