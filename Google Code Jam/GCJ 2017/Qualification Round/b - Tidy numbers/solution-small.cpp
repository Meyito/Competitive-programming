#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

    ifstream cin("b.in");
    ofstream cout("b.out");

	int TC, t, tam, i, j, start;
	string number;
	int rta[1000];
	bool nines;
	
	cin >> TC;
	t = 1;
	
	while( t <= TC ){
		cin >> number;
		
		nines = false;
		start = 0;
		tam = number.size();
		j = tam;
		rta[0] = number[0] - '0';
		
		for( i = 1; i < tam; i++ ){
			if( number[i] < number[i - 1] ){
				j = i;
				nines = true;
				break;
			}else{
				rta[i] = number[i] - '0';
			}
		}
		
		if( nines ){
			for( i = j - 1; i > 0; i-- ){
				rta[i]--;
				
				if( rta[i] >= rta[i - 1]) break;
				
				if( rta[i] == 0  ||  rta[i] == rta[i - 1] - 1 ) rta[i] = 9;
			}
			
			if( i == 0 ) rta[i]--; 
		}
		
		cout << "Case #" << t << ": " ;
		
		for( i = 0; i < j; i++ ){
			if( rta[i] != 0 ) cout << rta[i];
		}
		
		for( ; j < tam; j++ ){
			cout << 9;
		}
		
		cout << "\n";
		t++;
	}
	
	return 0;
}