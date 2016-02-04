#include <iostream>
using namespace std;

int main() {
	int n,i, open, rta;
	cin>>n;
	string s;
	
	while(n>0){
		cin>>s;
		open=rta=0;
		for(i=0; i<s.size(); i++){
			if(s[i]=='<'){
				open++;
			}
			
			if(s[i]=='>' && open>0){
				open--;
				rta++;
			}
		}
		
		cout<<rta<<"\n";
		n--;
	}
	return 0;
}