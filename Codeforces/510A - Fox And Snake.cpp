#include <iostream>
#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n,m, i, j;
	cin>>n>>m;
	bool aux=false;

	for(i=0; i<n; i++){
		if(i%2==0){
			for(j=0; j<m; j++){
				cout<<"#";
			}
		}else{
			if(aux){
				cout<<"#";
				for(j=1; j<m; j++){
					cout<<".";
				}
				aux=false;
			}else{
				for(j=0; j<(m-1); j++){
					cout<<".";
				}
				cout<<"#";
				aux=true;
			}
		}
		cout<<endl;
	}



}